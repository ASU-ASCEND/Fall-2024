#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "Sensor.h"

/**
 * @brief Implementation of a Sensor for the onboard temperature sensor
 *
 */
class TempSensor : public Sensor {
 private:
 public:
  TempSensor();
  TempSensor(unsigned long minium_period);
  bool verify();
  String readData();
};

#endif