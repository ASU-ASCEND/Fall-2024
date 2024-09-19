#ifndef BME680SENSOR_H
#define BME680SENSOR_H

#include "Sensor.h"
#include <string.h>
#include <Adafruit_BME680.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SPI.h> 

/**
 * @class BME680Sensor
 * @brief A class to interface with the Adafruit BME680 sensor for environmental data collection.
 * 
 * The BME680Sensor class is responsible for interacting with the BME680 sensor to gather environmental data such as
 * temperature, pressure, humidity, and gas resistance. It also provides an approximation of altitude based on sea level pressure.
 * 
 * This class inherits from the Sensor base class and overrides its virtual methods to implement the specific functionality 
 * required to read and verify data from the BME680 sensor.
 * 
 * Key functionalities:
 * - Verify sensor connection and setup.
 * - Retrieve sensor readings in CSV format for easy integration with data logging systems.
 * - Get sensor name and CSV header for consistency in data handling.
 * 
 * Usage example:
 * ```
 * BME680Sensor sensor;
 * if (sensor.verify()) {
 *     String data = sensor.readData();
 * }
 * ```
 * 
 */
class BME680Sensor : public Sensor {
    private:
        Adafruit_BME680 bme;
        String nameCompiled = "BME680"; 
        String csvHeaderCompiled = "BME680 Temp C, BME680 Pressure hPa, BME680 Humidity %, BME680 Gas KOhms, BME680 Approx Alt m, ";
    
    public:
        BME680Sensor();
        BME680Sensor(unsigned long minimum_period);

        const String& getSensorName() const;
        const String& getSensorCSVHeader() const; 
        
        bool verify() override;
        String readData() override;
        String readEmpty() const;
};

#endif