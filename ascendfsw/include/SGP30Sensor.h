
#ifndef SGP30SENSOR_H 
#define SGP30SENSOR_H

#include "Sensor.h"
#include <string.h>
#include <stdint.h>
#include <Arduino.h>
#include "Adafruit_SGP30.h"

class SGP30Sensor : public Sensor {
    private:
        Adafruit_SGP30 sgp; 
    public:
        SGP30Sensor();
        SGP30Sensor(unsigned long minimum_period);
        bool verify() override;
        String readData() override;
};

#endif