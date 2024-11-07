#ifndef PCF8523_H
#define PCF8523_H

#include "Sensor.h" // Include the Sensor header
#include <string>

class PCF8523 : public Sensor { // Inherit from Sensor
public:
    PCF8523();
    ~PCF8523();

    // Override the virtual functions from the Sensor class
    std::string getCSV() const override; // Returns data in CSV format
    bool verifySensor() const override; // Verifies if the sensor is operational

    // Other PCF8523-specific functions
    void initialize();
    int readTime();
    // Add any additional members or functions required for the PCF8523
};

#endif
