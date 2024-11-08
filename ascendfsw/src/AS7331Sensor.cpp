#include <AS7331Sensor.h>
#include <SparkFun_AS7331.h>

/**
 * @brief Construct a new AS7331Sensor (UVA/B/C Sensor) object with default
 * minimum_period of 0 ms
 *
 */
AS7331Sensor::AS7331Sensor() : AS7331Sensor(0) {}

/**
 * @brief Construct a new AS7331Sensor (UVA/B/C Sensor) object
 *
 * @param minium_period Minimum time to wait between readings in ms
 */
AS7331Sensor::AS7331Sensor(unsigned long minium_period)
    : Sensor("AS7331", "UVA(nm),UVB(nm),UVC(nm),", 3, minium_period) {}

/**
 * @brief Returns if the sensor can be reached
 *
 * @return true always
 * @return false never
 */
bool AS7331Sensor::verify() { return myUVSensor.begin(); }

/**
 * @brief Reads UV data
 *
 * @return String CSV line - UVA, UVB, UVC,
 */
String AS7331Sensor::readData() {
  myUVSensor.readAllUV();

  float uva = myUVSensor.getUVA();
  float uvb = myUVSensor.getUVB();
  float uvc = myUVSensor.getUVC();

  return String(uva) + "," + String(uvb) + "," + String(uvc) + ",";
}
