#ifndef SD_STORAGE_H
#define SD_STORAGE_H

#include <SD.h>

#include "Storage.h"

#define SD_CS_PIN 17

class SDStorage : public Storage {
 private:
  String file_name;

 public:
  SDStorage();
  bool verify();
  void store(String data);
};

#endif