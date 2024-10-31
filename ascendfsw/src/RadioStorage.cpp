#include "RadioStorage.h"

/**
 * @brief Construct a new RadioStorage object
 *
 */
RadioStorage::RadioStorage() : Storage("Radio") {}

/**
 * @brief Initialize UART1 (Serial1)
 *
 * @return true UART1 bus was succesfully initialized
 * @return false otherwise
 */
bool RadioStorage::verify() {
  Serial1.begin(115200);
  return Serial1;
}

/**
 * @brief Send data to the radio for transmitting
 *
 * @param data Data to transmit
 */
void RadioStorage::store(String data) { Serial1.println(data); }
