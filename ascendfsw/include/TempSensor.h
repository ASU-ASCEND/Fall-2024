#ifndef TEMP_SENSOR_H
#define TEMP_SENSOR_H

#include "Sensor.h"

class TempSensor : public Sensor {
 private:
 public:
  TempSensor() : TempSensor(0) {}
  TempSensor(unsigned long minium_period)
      : Sensor("PicoTemp", "PicoTemp(C),", 1, minium_period) {}

  bool verify();
  String readData();
};

#endif