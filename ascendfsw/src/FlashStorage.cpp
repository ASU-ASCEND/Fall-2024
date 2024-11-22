#include "FlashStorage.h"

/**
 * @brief Construct a new Flash Storage:: Flash Storage object
 *
 */
FlashStorage::FlashStorage() : position(0), Storage("Flash Storage") {}

/**
 * @brief Write new position to flash
 * 
 * @param new_pos 
 */
void FlashStorage::updatePosition(uint32_t new_pos) {
  this->flash.eraseSector(0); // Erase first 1kb sector
  this->position = new_pos;   // Update with new position

  // Write new position to flash
  uint8_t pos[4];
  for (int i = 3; i >= 0; i--) {
    pos[i] = (uint8_t)(new_pos >> (i * 8)) & 0xFF;
  }
  this->flash.writeBlock(0, pos, 4);
  this->flash.blockingBusyWait();
}

/**
 * @brief Read position from flash
 * 
 */
void FlashStorage::loadPosition() {
  uint8_t pos[4];
  this->flash.readBlock(0, pos, 4);
  this->position = 0;
  for (int i = 0; i < 4; i++) {
    this->position = (this->position << 8) | pos[i];
  }
}

/**
 * @brief Verify flash memory connection and create a new file
 *
 * @return true
 * @return false
 */
bool FlashStorage::verify() {
  if (this->flash.begin(FLASH_CS_PIN) == false)
    return false;
  Serial.println("Initial position: " + String(this->position));

  this->loadPosition(); // Get position from flash

  // Get position
  if (this->position == 0xFFFFFFFF) { 
    // Initialize position at start if position is empty (FFFF)
    this->updatePosition(this->DATA_START_POSITION);
  }
  else { 
    uint8_t currentByte = this->flash.readByte(this->position);

    // Shuffle through data at last recorded position until free space is reached
    while ((currentByte != 0xFF) && (this->position < this->MAX_SIZE)) {
      currentByte = this->flash.readByte(++this->position);
    }
  }

  // Update position stored in flash & print to console
  updatePosition(this->position);
  Serial.println("Updated position: " + String(this->position));

  return true;
}

/**
 * @brief Store data on flash
 *
 * @param data
 */
void FlashStorage::store(String data) {
  data = data + "\n";

  // uint8_t raw_data[data_len];

  // for (int i = 0; i < data.length(); i++) {
  //   raw_data[i] = data.charAt(i);
  // }
  // this->flash.writeBlock(this->position, raw_data, data_len);

  for(const uint8_t& character : data) {
    this->flash.writeByte(this->position, character);
    ++this->position;
    this->flash.blockingBusyWait();
  }

  Serial.println("Writing " + String(data.length()) + " bytes at " +
                 String(this->position));

  //   this->updatePosition(this->position + data_len);
  // this->position += data.length();

  this->flash.blockingBusyWait();

  if (this->position % 500 == 0) {
    updatePosition(this->position);
  } 
}

void FlashStorage::dump() {
  Serial.println("\nStarting data transfer: ");
  Serial.println("Position is at " + String(this->position));
  char data = '^';
  uint32_t pos = this->DATA_START_POSITION;
  // read until it hits end_code
  while ((pos < this->MAX_SIZE) && (pos < this->position) && (data != 0xFF)) {
    // digitalWrite(HEARTBEAT_PIN_0, (pos & 0x10) != 0);
    data = this->flash.readByte(pos);
    pos++;
    Serial.write(data);  // print as a character
    delay(10);
  }
}

void FlashStorage::erase() {
  this->flash.erase();
  this->updatePosition(this->DATA_START_POSITION);
}