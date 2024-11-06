#include "DS3231Sensor.h"

/**
 * @brief Default constructor for the BME680Sensor class.
 *
 * Initializes the sensor object with a default minimum period of 0
 * milliseconds.
 */
DS3231Sensor::DS3231Sensor() : DS3231Sensor(0) {}

/**
 * @brief Parameterized constructor for the BME680Sensor class.
 *
 * This constructor initializes the BME680Sensor with a specified minimum period
 * between sensor readings. It passes sensor-specific information like the name,
 * CSV header, number of fields, and the minimum period between reads to the
 * base Sensor class constructor.
 *
 * @param minimum_period The minimum time (in milliseconds) between consecutive
 * sensor reads.
 */
DS3231Sensor::DS3231Sensor(unsigned long minimum_period)
    : Sensor("DS3231",
             "DS3231Time,DS3231TempC,", 2,
             minimum_period) {}

/**
 * @brief Verifies the connection and readiness of the BME680 sensor.
 *
 * This function initializes the sensor and configures it by setting
 * temperature, humidity, and pressure oversampling, along with the gas heater
 * and IIR filter. It checks if the sensor is properly connected and ready for
 * reading data.
 *
 * @return true - If the sensor is detected and successfully initialized.
 * @return false - If the sensor is not detected or fails to initialize.
 */
bool DS3231Sensor::verify() {
  return rtc.begin(); 
}

String DS3231Sensor::readData() {
  DateTime now = rtc.now(); 

  return String(now.year()) + "/" + String(now.month()) + "/" + String(now.day()) + " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second()) + "," + String(rtc.getTemperature()) + ",";
}

void DS3231Sensor::setTime(int year, int month, int day, int hour, int minute, int second){
  rtc.adjust(DateTime(year, month, day, hour, minute, second)); 
}
