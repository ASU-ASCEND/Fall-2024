#include "BME680Sensor.h"

#define SEALEVELPRESSURE_HPA (1013.25)

/**
 * @brief Construct a new BME680Sensor object with a minimum period set to 0 ms
 * 
 */
BME680Sensor::BME680Sensor() : BME680Sensor(0) {}

/**
 * @brief Get the Sensor Name as an Arduino string
 * 
 * @return const String& 
 */
const String& BME680Sensor::getSensorName() const {
    return nameCompiled;
}

/**
 * @brief Get the CSV header string associated with BME680 sensor
 * 
 * @return const String& 
 */
const String& BME680Sensor::getSensorCSVHeader() const {
    return csvHeaderCompiled;
}

/**
 * @brief Verifies if the sensor is connected and working
 * 
 * @return true  - Connected
 * @return false - Not Connected
 */
bool BME680Sensor::verify() {
    if(!bme.begin()){
        return false;
    }

    // Set up oversampling and filter initialization
    bme.setTemperatureOversampling(BME680_OS_8X);
    bme.setHumidityOversampling(BME680_OS_2X);
    bme.setPressureOversampling(BME680_OS_4X);
    bme.setIIRFilterSize(BME680_FILTER_SIZE_3);
    bme.setGasHeater(320, 150); // 320*C for 150 ms

    return true;
}

/**
 * @brief Returns the collected data from the sensor in CSV format
 * 
 * @return String - "BME680 Temp C, BME680 Pressure hPa, BME680 Humidity %, BME680 Gas KOhms, BME680 Approx Alt m, "
 */
String BME680Sensor::readData() {
    if(!bme.performReading()){
        return "-, -, -, -, -, ";
    }

    return String(bme.temperature) + ", " + String(bme.pressure / 100.0) + ", " + String(bme.humidity) + ", " 
        + String(bme.gas_resistance) + ", " + String(bme.readAltitude(SEALEVELPRESSURE_HPA)) + ", ";
}