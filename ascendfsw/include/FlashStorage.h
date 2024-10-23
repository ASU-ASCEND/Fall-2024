#ifndef FLASH_STORAGE_H
#define FLASH_STORAGE_H

#include "Storage.h"

class FlashStorage : public Storage {
    private:
        String file_name;

    public:
        FlashStorage();
        bool verify();
        void store(String data);
};

#endif 