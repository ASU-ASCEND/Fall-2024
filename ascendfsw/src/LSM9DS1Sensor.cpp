#include "LSM9DS1Sensor.h"

/**
 * @brief Construct a new LSM9DS1Sensor object with default minimum_period of 0
 *
 */
LSM9DS1Sensor::LSM9DS1Sensor() : LSM9DS1Sensor(0) {}

/**
 * @brief Construct a new LSM9DS1Sensor object, given mininum_period between
 * sensor reads
 *
 * @param minimum_period Minimum time to wait between readings in ms
 */
LSM9DS1Sensor::LSM9DS1Sensor(unsigned long minimum_period)
    : Sensor("LSM9DS1",
             "LSM9DS1 AccX, LSM9DS1 AccY, LSM9DS1 AccZ, LSM9DS1 GyroX, LSM9DS1 "
             "GyroY, LSM9DS1 GyroZ, LSM9DS1 MagX, LSM9DS1 MagY, LSM9DS1 MagZ,",
              9, minimum_period),
      IMU(SPI_MODE, 10, 9) {  // Initialize IMU with SPI mode and chip select pins
}

/**
 * @brief Verifies that the LSM is connected and working
 *
 * @return true if connected and working
 * @return false if not connected and working
 */
bool LSM9DS1Sensor::verify() {
  return IMU.begin();
}

/**
 * @brief Retrieves data from LSM 9-axis IMU
 *
 * @return String A CSV section in format AccX, AccY, AccZ, GyroX, GyroY, GyroZ,
 * MagX, MagY, MagZ,
 */
String LSM9DS1Sensor::readData() {
  IMU.readAccelGyroMag();

  float accX = IMU.calcAccel(IMU.ax);
  float accY = IMU.calcAccel(IMU.ay);
  float accZ = IMU.calcAccel(IMU.az);

  float gyroX = IMU.calcGyro(IMU.gx);
  float gyroY = IMU.calcGyro(IMU.gy);
  float gyroZ = IMU.calcGyro(IMU.gz);

  float magX = IMU.calcMag(IMU.mx);
  float magY = IMU.calcMag(IMU.my);
  float magZ = IMU.calcMag(IMU.mz);

  return String(accX) + "," + String(accY) + "," + String(accZ) + "," +
         String(gyroX) + "," + String(gyroY) + "," + String(gyroZ) + "," +
         String(magX) + "," + String(magY) + "," + String(magZ) + ",";
}

/**
 * @brief Calibrates the LSM9DS1 sensor by collecting offset data for gyro and accel
 */
void LSM9DS1Sensor::calibrate() {
  Serial.println("Calibrating sensor... Please keep the sensor stationary.");
  delay(3000);  // Give some time for the user to place the sensor still

  IMU.calibrate(true);  // Perform automatic calibration for gyro and accel

  Serial.println("Calibration complete.");
}