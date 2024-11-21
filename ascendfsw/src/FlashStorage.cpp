#include "FlashStorage.h"

/**
 * @brief Construct a new Flash Storage:: Flash Storage object
 *
 */
FlashStorage::FlashStorage() : position(0), Storage("Flash Storage") {}

void FlashStorage::updatePosition(uint32_t new_pos) {
  this->position = new_pos;

  uint8_t pos[4];
  for (int i = 0; i < 4; i++) {
    pos[i] = (new_pos >> (i * 8)) & 0xFF;
  }
  this->flash.writeBlock(0, pos, 4);
  this->flash.blockingBusyWait();
}

void FlashStorage::loadPosition() {
  uint8_t pos[4];
  this->flash.readBlock(0, pos, 4);
  this->position = 0;
  for (int i = 0; i < 4; i++) {
    this->position = (this->position << 4) | pos[i];
  }
}

/**
 * @brief Verify flash memory connection and create a new file
 *
 * @return true
 * @return false
 */
bool FlashStorage::verify() {
  // TODO: Implement verify() function
  if (this->flash.begin(FLASH_CS_PIN, 2'000'000, SPI, SPI_MODE0) == false)
    return false;
  Serial.println("Initial position: " + String(this->position));

  //   this->updatePosition(this->data_start_position);
  //   this->flash.erase();
  //   this->updatePosition(this->data_start_position);

  //   this->loadPosition();
  //   // if this is a new session
  //   if (this->position == 0xFFFF || this->position == 0x0000) {
  //     this->updatePosition(this->data_start_position);
  //   }
  //   this->updatePosition(this->data_start_position);
  this->position = 10;

  Serial.println("Updated position: " + String(this->position));

  return true;
}

/**
 * @brief Store data on flash
 *
 * @param data
 */
void FlashStorage::store(String data) {
  // TODO: Implement store(String) function
  data = data + "\n";

  size_t data_len = data.length();
  uint8_t raw_data[data_len];

  for (int i = 0; i < data.length(); i++) {
    raw_data[i] = data.charAt(i);
  }

  this->flash.writeBlock(this->position, raw_data, data_len);

  Serial.println("Writing " + String(data_len) + " bytes at " +
                 String(this->position));
  this->flash.blockingBusyWait();

  //   this->updatePosition(this->position + data_len);
  this->position += data_len;
  this->flash.writeBlock(this->position, this->end_code, this->end_code_len);
  this->flash.blockingBusyWait();
}

void FlashStorage::dump() {
  Serial.println("\nStarting data transfer: ");
  Serial.println("Position is at " + String(this->position));
  char data = '^';
  uint32_t pos = this->data_start_position;
  // read until it hits end_code
  while (data != this->end_code[0] && pos < this->size_bytes &&
         pos < this->position) {
    // digitalWrite(HEARTBEAT_PIN_0, (pos & 0x10) != 0);
    data = this->flash.readByte(pos);
    pos++;
    Serial.write(data);  // print as a character
    delay(10);
  }
}

void FlashStorage::erase() {
  this->flash.erase();
  this->updatePosition(this->data_start_position);
}