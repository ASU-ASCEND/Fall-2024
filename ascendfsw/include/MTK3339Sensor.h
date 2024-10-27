#ifndef MTK3339SENSOR_H
#define MTK3339SENSOR_H

#include <Adafruit_GPS.h>
#include <Arduino.h>
#include <Wire.h>

#include "Sensor.h"

/**
 * @brief Implementation of the Adafruit MTK3339 GPS sensor
 *
 */
class MTK3339Sensor : public Sensor {
 private:
  Adafruit_GPS GPS = Adafruit_GPS(&Wire);

 public:
  MTK3339Sensor();
  MTK3339Sensor(unsigned long minimum_period);

  bool verify() override;
  String readData() override;
};

#endif