#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "Sensor.h"

class TempSensor : public Sensor {
 private:
 public:
  TempSensor();
  TempSensor(unsigned long minium_period);
  bool verify();
  String readData();
};

#endif