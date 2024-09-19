#include "GeigerSensor.h"

/**
 * @brief Default constructor for the GeigerSensor class.
 * 
 * Initializes the sensor object with a default minimum period of 0 milliseconds.
 */
GeigerSensor::GeigerSensor() : GeigerSensor(0) {}

/**
 * @brief Retrieves the sensor name.
 *
 * @return const String& - The name of the sensor.
 */
const String &GeigerSensor::getSensorName() const {
    return nameCompiled;
}

/**
 * @brief Retrieves the CSV header for the sensor data.
 *
 * @return const String& - The CSV header string for the sensor data.
 */
const String &GeigerSensor::getSensorCSVHeader() const {
    return csvHeaderCompiled;
}

/**
 * @brief Verifies the connection to the sensor and sets up the interrupt.
 *
 * @return true - If the sensor is successfully verified.
 * @return false - (Not applicable for this sensor, always returns true).
 */
bool GeigerSensor::verify() {
    attachInterrupt(digitalPinToInterrupt(GEIGER_PIN), geigerCounter, FALLING);
    measuringPeriodStart = millis();
    return true;
}

/**
 * @brief Reads the sensor data in CPS (counts per second) format.
 *
 * This function calculates the CPS value based on the number of counts recorded
 * over a set time period and resets the count for the next measurement period.
 *
 * @return String - The current CPS reading in CSV format.
 */
String GeigerSensor::readData() {
    int samplePeriod = millis() - measuringPeriodStart;

    noInterrupts();
    float CPS = count / (samplePeriod / 1000.0);
    count = 0;
    interrupts();

    measuringPeriodStart = millis();

    return String(CPS) + ", ";
}

/**
 * @brief Returns an empty CSV string when no valid data is available.
 *
 * @return String - A placeholder string formatted as "-, ".
 */
String GeigerSensor::readEmpty() {
    return "-, ";
}