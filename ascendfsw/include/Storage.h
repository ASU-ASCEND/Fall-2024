#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>

class Storage {
 private:
  String storage_name;

 public:
  const String& getStorageName() const { return this->storage_name; }
  virtual bool verify() = 0;
  virtual void store(String data) = 0;
};

#endif