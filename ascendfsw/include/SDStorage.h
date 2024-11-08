#ifndef SD_STORAGE_H
#define SD_STORAGE_H

#include "ErrorDisplay.h"
#include "SD.h"
#include "Storage.h"

#define SD_SPI1 1

#define SPI1_MISO 8
#define SD_CS_PIN 9
#define SPI1_SCK 10
#define SPI1_MOSI 11

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