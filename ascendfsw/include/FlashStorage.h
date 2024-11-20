#ifndef FLASH_STORAGE_H
#define FLASH_STORAGE_H

#include <SPI.h>
#include "Storage.h"
#include "PayloadConfig.h"
#include "SparkFun_SPI_SerialFlash.h"

class FlashStorage : public Storage {
    private:
        String file_name;
        SFE_SPI_FLASH flash;
        SPIClassRP2040 sd_spi_1 = SPIClassRP2040(spi1, SPI1_MISO_PIN, SD_CS_PIN,
                                                 SPI1_SCK_PIN, SPI1_MOSI_PIN);
        uint64_t position; 

    public:
        FlashStorage();
        bool verify() override;
        void store(String) override;
};

#endif 