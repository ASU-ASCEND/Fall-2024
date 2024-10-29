#ifndef SD_STORAGE_H
#define SD_STORAGE_H

#include "SD.h"
#include "Storage.h"

#include "ErrorDisplay.h"

#define SD_SPI1 0

#define SD_CS_PIN 7

/**
 * @brief Implementation of a Storage device to interface with an SD card
 *
 */
class SDStorage : public Storage {
 private:
  String file_name;
#if SD_SPI1
  SPIClassRP2040 sd_spi_1 = SPIClassRP2040(spi1, 8, 9, 10, 11);
#endif

 public:
  SDStorage();
  bool verify();
  void store(String data);
};

#endif