#ifndef PAYLOAD_CONFIG_H
#define PAYLOAD_CONFIG_H

/** Central location for pinout and config defines */

/** Error display bit 2 */
#define ERROR_PIN_2 2
/** Error display bit 1 */
#define ERROR_PIN_1 3
/** Error display bit 0 */
#define ERROR_PIN_0 6

// sensors
/** BME680 CS Pin */
#define BME680_SPI_CS_PIN 17
/** BME680 SPI Mode Toggle Pin */
#define BME680_SPI_MODE 0

/** ICM20948 IMU CS Pin */
#define ICM_CS_PIN 26
/** ICM20948 IMU I2C Toggle Pin */
#define ICM_I2C_MODE 1

/** LSM9DS1 IMU Accelerometer/Gyroscope Pin */
#define LSM9DS1_XGCS_PIN 21
/** LSM9DS1 IMU Magnetometer Pin */
#define LSM9DS1_MCS_PIN 22

// storages
// for radio
/** UART0 RX Pin */
#define SERIAL1_RX_PIN 1
/** UART0 RX Pin */
#define SERIAL1_TX_PIN 0

/** SD Card SPI Toggle */
#define SD_SPI1 1
/** SD Card SPI CS PIN */
#define SD_CS_PIN 9

// spi1
/** SPI1 MISO PIN */
#define SPI1_MISO_PIN 8
/** SPI1 SCK PIN */
#define SPI1_SCK_PIN 10
/** SPI1 MOSI PIN */
#define SPI1_MOSI_PIN 11

// main pin definitions
/** Built-in LED Pin */
#define ON_BOARD_LED_PIN 25
/** Core 0 Heartbeat Pin */
#define HEARTBEAT_PIN_0 12
/** Core 1 Heartbeat Pin */
#define HEARTBEAT_PIN_1 13
/** Flash Data Interface Enable Pin  */
#define DATA_INTERFACE_PIN 15

#endif