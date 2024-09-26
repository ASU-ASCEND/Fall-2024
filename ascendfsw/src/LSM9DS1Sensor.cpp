#include "LSM9DS1Sensor.h"

LSM9DS1Sensor::LSM9DS1Sensor() : LSM9DS1Sensor(0) {}

LSM9DS1Sensor::LSM9DS1Sensor(unsigned long minimum_period)
    : Sensor("LSM9DS1",
             "LSM9DS1 AccX, LSM9DS1 AccY, LSM9DS1 AccZ, LSM9DS1 GyroX, LSM9DS1 "
             "GyroY, LSM9DS1 GyroZ, LSM9DS1 MagX, LSM9DS1 MagY, LSM9DS1 MagZ,",
             9, minimum_period) {}

bool LSM9DS1Sensor::verify() {
  // return false;
  return IMU.begin();
}

// returns in format AccX, AccY, AccZ, GyroX, GyroY, GyroZ, MagX, MagY, MagZ,
String LSM9DS1Sensor::readData() {
  // return "-. -. -. -. -. -. -, -, -,";

  float accX, accY, accZ;
  IMU.readAcceleration(accX, accY, accZ);

  float gyroX, gyroY, gyroZ;
  IMU.readGyroscope(gyroX, gyroY, gyroZ);

  float magX, magY, magZ;
  IMU.readMagneticField(magX, magY, magZ);

  return String(accX) + ", " + String(accY) + ", " + String(accZ) + ", " +
         String(gyroX) + ", " + String(gyroY) + ", " + String(gyroZ) + ", " +
         String(magX) + ", " + String(magY) + ", " + String(magZ) + ", ";
}