#ifndef RADIO_STORAGE_H
#define RADIO_STORAGE_H

#include <Arduino.h>

#include "Storage.h"
#include "PayloadConfig.h"

/**
 * @brief Implementation of a Storage device to interface with an SD card
 *
 */
class RadioStorage : public Storage {
 private:
  String file_name;

 public:
  RadioStorage();
  bool verify();
  void store(String data);
};

#endif