#ifndef PAYLOAD_CONFIG_H
#define PAYLOAD_CONFIG_H

/**
 * @brief Central location for pinout and config defines
 *
 */

// error display
#define ERROR_PIN_2 2
#define ERROR_PIN_1 3
#define ERROR_PIN_0 6

// sensors
// bme 680
#define BME680_SPI_CS_PIN 17
#define BME680_SPI_MODE 0

// icm 20948 imu
#define ICM_CS_PIN 26
#define ICM_I2C_MODE 1

// lsm9ds1 imu
#define LSM9DS1_XGCS_PIN 21
#define LSM9DS1_MCS_PIN 22

// storages
// radio
#define SERIAL1_RX_PIN 1
#define SERIAL1_TX_PIN 0

// sd card
#define SD_SPI1 1
#define SD_CS_PIN 9

// spi1
#define SPI1_MISO_PIN 8
#define SPI1_SCK_PIN 10
#define SPI1_MOSI_PIN 11

// main pin definitions
#define ON_BOARD_LED_PIN 25
#define HEARTBEAT_PIN_0 12
#define HEARTBEAT_PIN_1 13
#define DATA_INTERFACE_PIN 15

#endif