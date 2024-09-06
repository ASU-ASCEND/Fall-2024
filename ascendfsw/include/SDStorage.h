#ifndef SD_STORAGE_H
#define SD_STORAGE_H

#include "Storage.h"

class SDStorage : public Storage {
 private:
 public:
  bool verify();
  void store(String data);
};

#endif