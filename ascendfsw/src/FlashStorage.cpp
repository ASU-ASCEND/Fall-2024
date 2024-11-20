#include "FlashStorage.h"

/**
 * @brief Construct a new Flash Storage:: Flash Storage object
 *
 */
FlashStorage::FlashStorage() : position(0), Storage("Flash Storage") {}

void FlashStorage::updatePosition(uint64_t new_pos) {
  this->position = new_pos;

  uint8_t pos[8];
  this->flash.readBlock(0, pos, 8);
  this->position = 0;
  for (int i = 0; i < 8; i++) {
    this->position = (this->position << 8) | pos[i];
  }
}

void FlashStorage::loadPosition() {
  uint8_t pos[8];
  this->flash.readBlock(0, pos, 8);
  this->position = 0;
  for (int i = 0; i < 8; i++) {
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
  // TODO: Implement verify() function
  if (this->flash.begin(FLASH_CS_PIN) == false) return false;

  this->loadPosition();
  // if this is a new session
  if (this->position == 0xFFFF'FFFF) {
    this->updatePosition(this->data_start_position);
  }

  return true;
}

/**
 * @brief Store data on flash
 *
 * @param data
 */
void FlashStorage::store(String data) {
  // TODO: Implement store(String) function
  size_t buf_size = data.length() + 5;  // + 5 for buffer
  uint8_t raw_data[buf_size];
  data.getBytes(raw_data, buf_size);

  this->flash.writeBlock(position, raw_data, buf_size);
  this->updatePosition(this->position + buf_size);
  this->flash.writeBlock(position, this->end_code, this->end_code_len);
}

void FlashStorage::dump() {
  uint8_t data = 0xFF;
  uint32_t pos = this->data_start_position;
  // read until it hits end_code
  while (data != this->end_code[0] && pos < this->size_bytes) {
    digitalWrite(HEARTBEAT_PIN_0, (pos & 0x10) != 0);
    data = this->flash.readByte(pos);
    pos++;
    Serial.print((char)data);  // print as a character
  }
}

void FlashStorage::erase() {
  this->flash.erase();
  this->updatePosition(this->data_start_position);
}