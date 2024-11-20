#ifndef PAYLOAD_CONFIG_H
/** @brief Central location for pinout and config defines */
#define PAYLOAD_CONFIG_H

/** @brief Error display bit 2 */
#define ERROR_PIN_2 2
/** @brief Error display bit 1 */
#define ERROR_PIN_1 3
/** @brief Error display bit 0 */
#define ERROR_PIN_0 6

// sensors
/** @brief BME680 CS Pin */
#define BME680_SPI_CS_PIN 17
/** @brief BME680 SPI Mode Toggle Pin */
#define BME680_SPI_MODE 0

/** @brief ICM20948 IMU CS Pin */
#define ICM_CS_PIN 26
/** @brief ICM20948 IMU I2C Toggle Pin */
#define ICM_I2C_MODE 1

/** @brief LSM9DS1 IMU Accelerometer/Gyroscope Pin */
#define LSM9DS1_XGCS_PIN 21
/** @brief LSM9DS1 IMU Magnetometer Pin */
#define LSM9DS1_MCS_PIN 22

/** @brief MTK3339 GPS CS Pin*/
#define MTK3339_CS_PIN 20

// storages
// for radio
/** @brief UART0 RX Pin */
#define SERIAL1_RX_PIN 1
/** @brief UART0 RX Pin */
#define SERIAL1_TX_PIN 0

/** @brief SD Card SPI Toggle */
#define SD_SPI1 1
/** @brief SD Card SPI CS Pin */
#define SD_CS_PIN 9

/** @brief Flash chip SPI CS Pin */
#define FLASH_CS 7

// spi1
/** @brief SPI1 MISO Pin */
#define SPI1_MISO_PIN 8
/** @brief SPI1 SCK Pin */
#define SPI1_SCK_PIN 10
/** @brief SPI1 MOSI Pin */
#define SPI1_MOSI_PIN 11

// main pin definitions
/** @brief Built-in LED Pin */
#define ON_BOARD_LED_PIN 25
/** @brief Core 0 Heartbeat Pin */
#define HEARTBEAT_PIN_0 12
/** @brief Core 1 Heartbeat Pin */
#define HEARTBEAT_PIN_1 13
/** @brief Flash Data Interface Enable Pin  */
#define DATA_INTERFACE_PIN 15

#endif