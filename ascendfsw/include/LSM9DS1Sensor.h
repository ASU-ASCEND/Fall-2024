#ifndef LSM9DS1SENSOR_H
#define LSM9DS1SENSOR_H

#include <Arduino_LSM9DS1.h>
#include <string.h>

#include "Sensor.h"

class LSM9DS1Sensor : public Sensor {
 private:
 public:
  LSM9DS1Sensor();
  LSM9DS1Sensor(unsigned long minimum_period);
  bool verify() override;
  String readData() override;
};

#endif