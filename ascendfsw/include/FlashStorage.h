#ifndef FLASH_STORAGE_H
#define FLASH_STORAGE_H

#include <SPI.h>

#include "PayloadConfig.h"
#include "SparkFun_SPI_SerialFlash.h"
#include "Storage.h"

class FlashStorage : public Storage {
 private:
  // position after position bytes + 2 bytes for buffer
  inline static const uint32_t data_start_position = 10;
  inline static const uint32_t size_bytes =
      15'000'000;  // 16 MByte (less for safety)
  inline static const uint8_t end_code_len = 8;
  inline static uint8_t end_code[end_code_len] = {'|', '|', '|', '|',
                                                  '|', '|', '|', '|'};
  String file_name;
  SFE_SPI_FLASH flash;
  uint32_t position;
  void loadPosition();
  void updatePosition(uint32_t new_pos);

 public:
  FlashStorage();
  bool verify() override;
  void store(String) override;
  void dump();
  void erase();
};

#endif