#ifndef BME680SENSOR_H
#define BME680SENSOR_H

#include <Adafruit_BME680.h>
#include <Adafruit_Sensor.h>
#include <SPI.h>
#include <Wire.h>
#include <string.h>

#include "Sensor.h"

#define SEALEVELPRESSURE_HPA (1013.25)
#define BME680_SPI_MODE 0
#define SPI_CS_PIN 17

/**
 * @class BME680Sensor
 * @brief A class to interface with the Adafruit BME680 sensor for environmental
 * data collection.
 *
 * The BME680Sensor class is responsible for interacting with the BME680 sensor
 * to gather environmental data such as temperature, pressure, humidity, and gas
 * resistance. It also provides an approximation of altitude based on sea level
 * pressure.
 *
 * This class inherits from the Sensor base class and overrides its virtual
 * methods to implement the specific functionality required to read and verify
 * data from the BME680 sensor.
 *
 * Key functionalities:
 * - Verify sensor connection and setup.
 * - Retrieve sensor readings in CSV format for easy integration with data
 * logging systems.
 * - Get sensor name and CSV header for consistency in data handling.
 */
class BME680Sensor : public Sensor {
 private:
  Adafruit_BME680 bme;

 public:
  BME680Sensor();
  BME680Sensor(unsigned long minimum_period);

  bool verify() override;
  String readData() override;
};

#endif