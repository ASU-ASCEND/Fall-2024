#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

/**
 * @brief Interface for sensor objects
 * 
 */
class Sensor {
 private:
  unsigned long minimum_period;
  unsigned long last_execution;

 public:
  /**
   * @brief Construct a new Sensor object with default minimum_period of 0
   *
   */
  Sensor() {
    this->minimum_period = 0;
    this->last_execution = 0;
  }

  /**
   * @brief Construct a new Sensor object with custom minimum_period
   *
   * @param minimum_period
   */
  Sensor(unsigned long minimum_period) {
    this->minimum_period = minimum_period;
    this->last_execution = 0;
  }

  /**
   * @brief Get the minimum minimum_period between sensor reads in ms
   *
   * @return unsigned long
   */
  unsigned long getPeriod() { return minimum_period; }

  /**
   * @brief Set the minimum minimum_period between sensor reads in ms
   *
   * @param minimum_period the new minimum_period in ms
   */
  void setPeriod(int minimum_period) { this->minimum_period = minimum_period; }

  /**
   * @brief Get the system time of the last execution in ms
   *
   * @return unsigned long
   */
  unsigned long getLastExecution() { return last_execution; }

  /**
   * @brief Set the system time of the last execution in ms
   *
   * @param last_execution system time of last execution im ms
   */
  void setLastExecution(int last_execution) {
    this->last_execution = last_execution;
  }

  /**
   * @brief Get the Sensor Name as an Arduino string
   *
   * @return const String&
   */
  virtual const String& getSensorName() const = 0;

  /**
   * @brief Get the csv header string associated with this sensor
   *
   * @return const String&
   */
  virtual const String& getSensorCSVHeader() const = 0;

  /**
   * @brief Verifies if the sensor is connected and working
   *
   * @return true, if connected
   * @return false, if not connected
   */
  virtual bool verify() = 0;

  /**
   * @brief Returns the collected data from the sensor in CSV format
   *
   * @return String
   */
  virtual String readData() = 0;

  /**
   * @brief Returns CSV line in the same format as readData() but with "-"
   * instead of data
   *
   * @return String
   */
  virtual String readEmpty() = 0;

  /**
   * @brief Uses readData and readEmpty to get the data-filled or empty-celled
   * CSV line for the sensor
   *
   * @return String
   */
  String getDataCSV() {
    if (millis() - this->last_execution >= this->minimum_period) {
      this->last_execution = millis();
      return readData();
    } else {
      return readEmpty();
    }
  }
};
#endif
