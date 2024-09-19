#include "BME680Sensor.h"

#define SEALEVELPRESSURE_HPA (1013.25)

/**
 * @brief Default constructor for the BME680Sensor class.
 * 
 * Initializes the sensor object with a default minimum period of 0 milliseconds.
 */
BME680Sensor::BME680Sensor() : BME680Sensor(0) {}

/**
 * @brief Retrieves the sensor's name.
 * 
 * This function returns the name of the sensor, which is compiled into a string.
 * Useful for identifying the sensor in logs or reports.
 * 
 * @return const String& - A reference to the string containing the sensor name ("BME680").
 */
const String& BME680Sensor::getSensorName() const {
    return nameCompiled;
}

/**
 * @brief Retrieves the CSV header for the sensor's data.
 * 
 * Returns a pre-defined CSV header string that represents the labels for the sensor's output data fields.
 * 
 * @return const String& - A reference to the string containing the CSV header for the BME680 sensor.
 */
const String& BME680Sensor::getSensorCSVHeader() const {
    return csvHeaderCompiled;
}

/**
 * @brief Verifies the connection and readiness of the BME680 sensor.
 * 
 * This function initializes the sensor and configures it by setting temperature, humidity,
 * and pressure oversampling, along with the gas heater and IIR filter. It checks if the sensor
 * is properly connected and ready for reading data.
 * 
 * @return true - If the sensor is detected and successfully initialized.
 * @return false - If the sensor is not detected or fails to initialize.
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
    bme.setGasHeater(320, 150); // 320°C for 150 ms

    return true;
}

/**
 * @brief Reads sensor data and returns it in CSV format.
 * 
 * Performs a reading from the BME680 sensor, which includes temperature, pressure, humidity,
 * gas resistance, and an approximate altitude based on sea-level pressure. 
 * If the sensor fails to perform a reading, a placeholder string ("-, -, -, -, -, ") is returned.
 * 
 * @return String - A string containing the sensor readings formatted as:
 * "Temperature (Celsius), Pressure (hPa), Humidity (%), Gas Resistance (KOhms), Altitude (meters)".
 */
String BME680Sensor::readData() {
    if(!bme.performReading()){
        return "-, -, -, -, -, ";
    }

    return String(bme.temperature) + ", " + String(bme.pressure / 100.0) + ", " + String(bme.humidity) + ", " 
        + String(bme.gas_resistance) + ", " + String(bme.readAltitude(SEALEVELPRESSURE_HPA)) + ", ";
}

/**
 * @brief Returns an empty CSV string placeholder.
 * 
 * This function is used when the sensor is unable to provide valid data,
 * or if the sensor reading fails. It returns a placeholder CSV string 
 * representing unavailable or invalid sensor data.
 * 
 * @return String - A string formatted as "-, -, -, -, -, " representing 
 * missing or unavailable data for temperature, pressure, humidity, gas resistance, and altitude.
 */
String BME680Sensor::readEmpty() const {
    return "-, -, -, -, -, ";
}
