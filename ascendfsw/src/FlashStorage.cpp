#include "FlashStorage.h"

/**
 * @brief Construct a new Flash Storage:: Flash Storage object
 *
 */
FlashStorage::FlashStorage() : position(0), Storage("Flash Storage") {}

/**
 * @brief Verify flash memory connection and create a new file
 *
 * @return true
 * @return false
 */
bool FlashStorage::verify() {
<<<<<<< HEAD
    // TODO: Implement verify() function
    if(this->flash.begin(FLASH_CS_PIN) == false) return false; 

    uint8_t pos[8];
    this->flash.readBlock(0, pos, 8);
    for(int i = 0; i < 8; i++){
        this->position = (this->position << 8) | pos[i];
    }
    this->position += 10;  // 2 bytes buffer

    return true; 
=======
  // TODO: Implement verify() function
  return this->flash.begin(FLASH_CS_PIN);
>>>>>>> b5372a6ec2854fe3256b61c74532827aebec0424
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
    this->position += buf_size; 
    
    uint8_t pos[8]; 
    for(int i = 0; i < 8; i++){
        pos[i] = (uint8_t)((this->position >> (i * 8)) & 0xFF);
    }

    this->flash.writeBlock(0, pos, 8);
}