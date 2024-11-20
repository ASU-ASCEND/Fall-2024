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
    // TODO: Implement verify() function
    return this->flash.begin(FLASH_CS);
}

/**
 * @brief Store data on flash
 * 
 * @param data 
 */
void FlashStorage::store(String data) {
    // TODO: Implement store(String) function
    size_t buf_size = data.length() + 5; // + 5 for buffer 
    uint8_t raw_data[buf_size]; 
    data.getBytes(raw_data, buf_size);  

    this->flash.writeBlock(position, raw_data, buf_size); 
    position += buf_size; 
}