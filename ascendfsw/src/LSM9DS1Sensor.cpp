#include "LSM9DS1Sensor.h"

/**
 * @brief Construct a new LSM9DS1Sensor object with default minimum_period of 0
 * 
 */
LSM9DS1Sensor::LSM9DS1Sensor() : LSM9DS1Sensor(0) {}

/**
 * @brief Construct a new LSM9DS1Sensor object, given mininum_period between sensor reads
 * 
 * @param minimum_period Minimum time to wait between readings in ms
 */
LSM9DS1Sensor::LSM9DS1Sensor(unsigned long minimum_period)
    : Sensor("LSM9DS1",
             "LSM9DS1 AccX, LSM9DS1 AccY, LSM9DS1 AccZ, LSM9DS1 GyroX, LSM9DS1 "
             "GyroY, LSM9DS1 GyroZ, LSM9DS1 MagX, LSM9DS1 MagY, LSM9DS1 MagZ,",
             9, minimum_period) {}

/**
 * @brief Verifies that the LSM is connected and working
 * 
 * @return true if connected and working
 * @return false if not connected and working
 */
bool LSM9DS1Sensor::verify() {
  // return false;
  return IMU.begin();
}

/**
 * @brief Retrieves data from LSM 9-axis IMU
 * 
 * @return String A CSV section in format AccX, AccY, AccZ, GyroX, GyroY, GyroZ, MagX, MagY, MagZ,
 */
String LSM9DS1Sensor::readData() {

  float accX, accY, accZ;
  IMU.readAcceleration(accX, accY, accZ);

  float gyroX, gyroY, gyroZ;
  IMU.readGyroscope(gyroX, gyroY, gyroZ);

  float magX, magY, magZ;
  IMU.readMagneticField(magX, magY, magZ);

  return String(accX) + "," + String(accY) + "," + String(accZ) + "," +
         String(gyroX) + "," + String(gyroY) + "," + String(gyroZ) + "," +
         String(magX) + "," + String(magY) + "," + String(magZ) + ",";
}