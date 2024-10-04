#include <Arduino.h>

#include "Sensor.h"
#include "Storage.h"
// include sensor headers here
#include "AnalogSensor.h"
#include "BME680Sensor.h"
#include "GeigerSensor.h"
#include "INA260Sensor.h"
#include "LSM9DS1Sensor.h"
#include "SGP30Sensor.h"
#include "SHT31Sensor.h"
#include "TempSensor.h"
#include "ZOPT220Sensor.h"

#define ON_BOARD_LED_PIN 25

// helper function definitions
int verifySensors();
int verifyStorage();
void storeData(String data);

// Global variables
// sensor classes
BME680Sensor bme_sensor;
GeigerSensor geiger_sensor;
INA260Sensor ina260_sensor;
LSM9DS1Sensor lsm9ds1_sensor;
SHT31Sensor sht31_sensor;
TempSensor temp_sensor;
ZOPT220Sensor zopt220_sensor;
AnalogSensor analog_sensor;
SGP30Sensor sgp30_sensor;

// sensor array
Sensor* sensors[] = {&bme_sensor,     &geiger_sensor, &ina260_sensor,
                     &lsm9ds1_sensor, &sht31_sensor,  &temp_sensor,
                     &zopt220_sensor, &analog_sensor, &sgp30_sensor};
const int sensors_len = sizeof(sensors) / sizeof(sensors[0]);
bool sensors_verify[sensors_len];

// include storage headers here
#include "SDStorage.h"

// storage classes
SDStorage sd_storage;

// storage array
Storage* storages[] = {&sd_storage};
const int storages_len = sizeof(storages) / sizeof(storages[0]);
bool storages_verify[storages_len];

// loop counter
unsigned int it = 0;

/**
 * @brief Setup for core 0
 *
 */
void setup() {
  // start serial
  Serial.begin(115200);
  while (!Serial)
    ;
  delay(5000);  // wait for 5 seconds to ensure serial is initialized

  // verify sensors
  if (verifySensors() == 0) {
    Serial.println("All sensor communications failed");
    while (1) {
      Serial.println("Error");
      delay(1000);
    }
  } else {
    Serial.println("At least one sensor works, continuing");
  }

  // verify storage
  if (verifyStorage() == 0) {
    Serial.println("No storages verified, output will be Serial only.");
  }

  // build csv header
  String header = "Millis,";
  for (int i = 0; i < sensors_len; i++) {
    if (sensors_verify[i]) {
      header += sensors[i]->getSensorCSVHeader();
    }
  }
  Serial.println(header);

  // store header
  storeData(header);

  pinMode(ON_BOARD_LED_PIN, OUTPUT);
}

/**
 * @brief Loop for core 0, handling sensor reads
 *
 */
void loop() {
  it++;
  Serial.print("it: " + String(it) + "\t");

  // build csv row
  String csv_row = String(millis()) + ",";
  for (int i = 0; i < sensors_len; i++) {
    csv_row += sensors[i]->getDataCSV();
  }
  Serial.println(csv_row);

  // store csv
  storeData(csv_row);

  delay(500);
  digitalWrite(ON_BOARD_LED_PIN, it % 2);
}

/**
 * @brief Verifies each sensor by calling each verify() function
 *
 * @return int The number of verified sensors
 */
int verifySensors() {
  int count = 0;
  for (int i = 0; i < sensors_len; i++) {
    sensors_verify[i] = sensors[i]->verify();
    if (sensors_verify[i]) count++;
  }
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
 * @brief Verifies the connection with each storage device
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
 * @brief Sends data to each storage device
 *
 * @param data Data in a CSV formatted string
 */
void storeData(String data) {
  for (int i = 0; i < storages_len; i++) {
    storages[i]->store(data);
  }
}

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
