#ifndef AS7331SENSOR_H
#define AS7331SENSOR_H

#include <SparkFun_AS7331.h>
#include <Wire.h>
#include "Sensor.h"
#include <string.h>

class AS7331Sensor : public Sensor {
 
 private:
 SfeAS7331ArdI2C myUVSensor;
 
 public:
  AS7331Sensor();
  AS7331Sensor(unsigned long minimum_period);

  bool verify() override;
  String readData() override;
};

#endif 

