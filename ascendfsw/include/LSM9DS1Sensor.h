#ifndef LSM9DS1SENSOR_H
#define LSM9DS1SENSOR_H

#include <SparkFunLSM9DS1.h>  // Updated to use the SparkFun library
#include <string.h>

#include "Sensor.h"

/**
 * @brief Implementation of the Sensor class for the LSM9DS1 (9-axis IMU)
 *
 */
class LSM9DS1Sensor : public Sensor {
 private:
  LSM9DS1 IMU;  // Declaring an instance of the LSM9DS1 class

 public:
  LSM9DS1Sensor();
  LSM9DS1Sensor(unsigned long minimum_period);
  bool verify() override;
  String readData() override;
  void calibrate();  // New calibration function
};

#endif