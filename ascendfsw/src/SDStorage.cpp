#include "SDStorage.h"

/**
 * @brief Construct a new SDStorage object
 *
 */
SDStorage::SDStorage() : Storage("SD Card") {}

/**
 * @brief Verify SD card connection and create a new, unique file
 *
 * @return true if SD card is connected and file is successfully created
 * @return false otherwise
 */
bool SDStorage::verify() {
  // initialize SD card w/ instance
  if (!SD.begin(SD_CS_PIN, SPI)) return false;

  // find unused file name
  int num = 0;
  while (SD.exists("DATA" + String(num) + ".CSV")) num++;
  this->file_name = "DATA" + String(num) + ".CSV";

  // create file
  File f = SD.open(this->file_name, FILE_WRITE);
  if (!f) return false;  // check to see if the open operation worked
  f.close();

  return true;
}

/**
 * @brief Store data on the SD card, ending with newline
 *
 * @param data Data to store
 */
void SDStorage::store(String data) {
  File output = SD.open(this->file_name, FILE_WRITE);
  if (!output) Serial.println("SD card write failed");

  output.println(data);

  output.close();
}