#ifndef FLASH_STORAGE_H
#define FLASH_STORAGE_H

#include <SPI.h>

#include "PayloadConfig.h"
#include "SparkFun_SPI_SerialFlash.h"
#include "Storage.h"

class FlashStorage : public Storage {
 private:
  // position after position bytes + 2 bytes for buffer
  inline static const uint32_t DATA_START_POSITION = 0;
  inline static const uint32_t MAX_SIZE =
      15'000'000;  // 16 MByte (less for safety)
  SFE_SPI_FLASH flash;
  uint32_t position;
  void loadPosition();

 public:
  FlashStorage();
  bool verify() override;
  void store(String) override;
  void dump();
  void erase();
};

#endif