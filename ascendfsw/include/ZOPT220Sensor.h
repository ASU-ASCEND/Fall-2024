#ifndef ZOPT220SENSOR_H
#define ZOPT220SENSOR_H

#include "Sensor.h"
#include "ZOPT220x_Control.h"
#include <string.h>
#include <Arduino.h>
#include <Wire.h>

class ZOPT220Sensor : public Sensor {
    public:
        ZOPT220Sensor();
        ZOPT220Sensor(unsigned long mimimum_period);

        bool verify() override;
        arduino::String readData() override;
};

#endif