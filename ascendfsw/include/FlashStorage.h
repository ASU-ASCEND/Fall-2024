#ifndef FLASH_STORAGE_H
#define FLASH_STORAGE_H

#include <SPI.h>

#include "PayloadConfig.h"
#include "SparkFun_SPI_SerialFlash.h"
#include "Storage.h"

class FlashStorage : public Storage {
 private:
  String file_name;
  SFE_SPI_FLASH flash;
  uint64_t position;

 public:
  FlashStorage();
  bool verify() override;
  void store(String) override;
};

#endif