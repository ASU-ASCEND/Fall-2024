#ifndef BME680SENSOR_H
#define BME680SENSOR_H

#include "Sensor.h"
#include <string.h>
#include <Adafruit_BME680.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <SPI.h> 

class BME680Sensor : public Sensor {
    private:
        Adafruit_BME680 bme;
        String nameCompiled = "BME680"; 
        String csvHeaderCompiled = "BME680 Temp C, BME680 Pressure hPa, BME680 Humidity %, BME680 Gas KOhms, BME680 Approx Alt m, ";
    public:
        /**
         * @brief Construct a new default BME680Sensor object
         * 
         */
        BME680Sensor();

        /**
         * @brief Construct a new BME680Sensor object
         * 
         * @param minimum_period Set the minimum time between sensor reads in ms
         */
        BME680Sensor(unsigned long minimum_period);

        /**
         * @brief Get the Sensor Name as an Arduino string
         * 
         * @return const String& 
         */
        const String& getSensorName() const;

        /**
         * @brief Get the CSV header string associated with BME680 sensor
         * 
         * @return const String& 
         */
        const String& getSensorCSVHeader() const; 

        /**
         * @brief Verifies if the sensor is connected and working
         * 
         * @return true  - connected
         * @return false - not connected
         */
        bool verify() override;

        /**
         * @brief Returns the collected data from the sensor in CSV format
         * 
         * @return String 
         */
        String readData() override;

        /**
         * @brief Returns CSV line in the same format as readData() but with "-" instead of data
         * 
         * @return String 
         */
        String readEmpty() const {
            return "-, -, -, -, -, ";
        }
};

#endif