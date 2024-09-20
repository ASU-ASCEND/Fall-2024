#ifndef INA260SENSOR_H 
#define INA260SENSOR_H

#include "Sensor.h"
#include <string.h>
#include <Arduino.h>
#include "Adafruit_INA260.h"

class INA260Sensor : public Sensor {
    private:
        Adafruit_INA260 ina260;

    public:
        INA260Sensor();
        INA260Sensor(unsigned long minimum_period);

        bool verify() override;
        String readData() override;
};

#endif
