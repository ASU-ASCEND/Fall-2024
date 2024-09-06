#include "TempSensor.h"

/**
 * @brief Returns if sensor can be reached, the temperature sensor is on the
 * pico so it is assumed to be always true, implemented only for compatability
 * with parent
 *
 * @return true always
 * @return false never
 */
bool TempSensor::verify() {
  return true;
}

/**
 * @brief Reads temperature data in Celsius
 *
 * @return String Temperature data in CSV format
 */
String TempSensor::readData() {
  return String(analogReadTemp()) + ",";
}
