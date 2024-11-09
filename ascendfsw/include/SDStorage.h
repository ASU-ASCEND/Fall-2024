#ifndef SD_STORAGE_H
#define SD_STORAGE_H

#include "ErrorDisplay.h"
#include "SD.h"
#include "Storage.h"

#include "PayloadConfig.h"

/**
 * @brief Implementation of a Storage device to interface with an SD card
 *
 */
class SDStorage : public Storage {
 private:
  String file_name;
#if SD_SPI1
  SPIClassRP2040 sd_spi_1 =
      SPIClassRP2040(spi1, SPI1_MISO, SD_CS_PIN, SPI1_SCK, SPI1_MOSI);
#endif

 public:
  SDStorage();
  bool verify();
  void store(String data);
};

#endif