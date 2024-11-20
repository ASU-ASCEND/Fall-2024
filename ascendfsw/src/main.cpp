#include <Arduino.h>

// error code framework
#include "ErrorDisplay.h"
#include "PayloadConfig.h"

// parent classes
#include "Sensor.h"
#include "Storage.h"

// include sensor headers here
#include "AS7331Sensor.h"
#include "BME280Sensor.h"
#include "BME680Sensor.h"
#include "DS3231Sensor.h"
#include "ENS160Sensor.h"
#include "ICM20948Sensor.h"
#include "INA260Sensor.h"
#include "LSM9DS1Sensor.h"
#include "MTK3339Sensor.h"
#include "SGP30Sensor.h"
#include "SHT31Sensor.h"
#include "TempSensor.h"

// helper function definitions
int verifySensors();
int verifyStorage();
void storeData(String data);
String readSensorData();
void handleDataInterface();

// Global variables
// sensor classes
// clang-format off
// class        sensor            minimum period in ms
BME680Sensor    bme_sensor        (1000);
INA260Sensor    ina260_sensor     (1000);
LSM9DS1Sensor   lsm9ds1_sensor    (0);
SHT31Sensor     sht31_sensor      (1000);
TempSensor      temp_sensor       (1000);
SGP30Sensor     sgp30_sensor      (1000);
BME280Sensor    bme280_sensor     (1000);
ENS160Sensor    ens160_sensor     (1000);
AS7331Sensor    uv_sensor_1       (1000, UV_I2C_ADDR_1);
AS7331Sensor    uv_sensor_2       (1000, UV_I2C_ADDR_2);
DS3231Sensor    rtc_backup_sensor (1000);
MTK3339Sensor   gps_sensor        (5000);
ICM20948Sensor  icm_sensor        (20);
// clang-format on

// sensor array
Sensor* sensors[] = {&rtc_backup_sensor, &bme_sensor,    &ina260_sensor,
                     &lsm9ds1_sensor,    &sht31_sensor,  &temp_sensor,
                     &sgp30_sensor,      &bme280_sensor, &ens160_sensor,
                     &uv_sensor_1, &uv_sensor_2,  &icm_sensor,    &gps_sensor};
//&gps_sensor};
const int sensors_len = sizeof(sensors) / sizeof(sensors[0]);
bool sensors_verify[sensors_len];
String header_condensed = "";

// include storage headers here
#include "RadioStorage.h"
#include "SDStorage.h"

// storage classes
SDStorage sd_storage;
RadioStorage radio_storage;

// storage array
Storage* storages[] = {&sd_storage, &radio_storage};
const int storages_len = sizeof(storages) / sizeof(storages[0]);
bool storages_verify[storages_len];

// global variables for main
// loop counter
unsigned int it = 0;

/**
 * @brief Setup for core 0
 *
 */
void setup() {
  ErrorDisplay::instance().addCode(Error::NONE);  // for safety

  // start serial
  Serial.begin(115200);
  while (!Serial)  // remove before flight
    ;

  // setup heartbeat pins
  pinMode(HEARTBEAT_PIN_0, OUTPUT);
  pinMode(HEARTBEAT_PIN_1, OUTPUT);

  // verify sensors
  int verified_count = verifySensors();
  if (verified_count == 0) {
    Serial.println("All sensor communications failed");
    ErrorDisplay::instance().addCode(Error::CRITICAL_FAIL);
    while (1) {
      ErrorDisplay::instance().toggle();
      Serial.println("Error");
      delay(1000);
    }
  } else {
    Serial.println("At least one sensor works, continuing");
    if (verified_count < 5) {
      ErrorDisplay::instance().addCode(Error::LOW_SENSOR_COUNT);
    }
  }

  // verify storage
  Serial.println("Verifying storage...");
  verified_count = verifyStorage();
  if (verified_count == 0) {
    Serial.println("No storages verified, output will be Serial only.");
    ErrorDisplay::instance().addCode(Error::CRITICAL_FAIL);
  }

  // build csv header
  String header = "Header,Millis,";
  for (int i = 0; i < sensors_len; i++) {
    if (sensors_verify[i]) {
      header += sensors[i]->getSensorCSVHeader();
    }
  }
  Serial.println(header);

  // store header
  storeData(header);

  pinMode(ON_BOARD_LED_PIN, OUTPUT);
  Serial.println("Setup done.");
}

/**
 * @brief Loop for core 0, handling sensor reads
 *
 */
void loop() {
  it++;

  // toggle error display
  ErrorDisplay::instance().toggle();

  // toggle heartbeats
  digitalWrite(HEARTBEAT_PIN_0, (it & 0x1));
  digitalWrite(HEARTBEAT_PIN_1, (it & 0x1));

  // switch to data recovery mode
  if (digitalRead(DATA_INTERFACE_PIN) == HIGH) {
    handleDataInterface();
    return;
  }

  // start print line with iteration number
  Serial.print("it: " + String(it) + "\t");

  // build csv row
  String csv_row = readSensorData();

  // print csv row
  Serial.println(csv_row);

  // store csv row
  storeData(csv_row);

  delay(500);                                  // remove before flight
  digitalWrite(ON_BOARD_LED_PIN, (it & 0x1));  // toggle light with iteration
}

/**
 * @brief Verifies each sensor by calling each verify() function
 *
 * @return int The number of verified sensors
 */
int verifySensors() {
  int count = 0;
  uint32_t bit_array = 0b11;  // start with a bit for header and for millis
                              // (they will always be there)
  for (int i = 0; i < sensors_len; i++) {
    sensors_verify[i] = sensors[i]->verify();
    if (sensors_verify[i]) {
      count++;
      bit_array =
          (bit_array << 1) | 0b1;  // if the sensor is verified shift a 1 in
    } else {
      bit_array = (bit_array << 1);  // otherwise shift a 0 in
    }
  }
  header_condensed =
      String(bit_array, HEX);  // translate it to hex to condense it for the csv

  Serial.println("Pin Verification Results:");
  for (int i = 0; i < sensors_len; i++) {
    Serial.print(sensors[i]->getSensorName());
    Serial.print(": ");
    Serial.println(sensors_verify[i]
                       ? "Successful in Communication"
                       : "Failure in Communication (check wirings and/ or pin "
                         "definitions in the respective sensor header file)");
  }
  Serial.println();
  return count;
}

/**
 * @brief Read data from each verified Sensor
 *
 * @return String Complete CSV row for iteration
 */
String readSensorData() {
  String csv_row = header_condensed + "," + String(millis()) + ",";
  for (int i = 0; i < sensors_len; i++) {
    if (sensors_verify[i]) {
      csv_row += sensors[i]->getDataCSV();
    }
  }
  return csv_row;
}

/**
 * @brief Verifies the connection with each storage device, and defines the
 * header_condensed field
 *
 * @return int The number of verified storage devices
 */
int verifyStorage() {
  int count = 0;
  for (int i = 0; i < storages_len; i++) {
    storages_verify[i] = storages[i]->verify();
    if (storages_verify[i]) {
      Serial.println(storages[i]->getStorageName() + " verified.");
      count++;
    }
  }
  return count;
}

/**
 * @brief Sends data to each storage device, assumes storage devices take care
 * of newline/data end themselves
 *
 * @param data Data in a CSV formatted string
 */
void storeData(String data) {
  for (int i = 0; i < storages_len; i++) {
    storages[i]->store(data);
  }
}

/**
 * @brief Handles data interface mode for retrieving data from flash memory
 *
 */
void handleDataInterface() { delay(100); }

/** -------------------------------------------------------------------
 * CORE 1 CODE ONLY AFTER THIS, DO NOT MIX CODE FOR THE CORES
 *  -------------------------------------------------------------------
 * TODO: Implement multicore for communication here
 * setup queue for data transfer between cores
 *
 */

// /**
//  * @brief Setup for core 1
//  *
//  *
//  */
// void setup1() {}

// /**
//  * @brief Loop for core 1
//  *
//  */
// void loop1() {
//   Serial.println("Core 1: " + String(millis()));
//   delay(1000);
// }
