# Hardware

## Microcontroller 
[Raspberry Pi Pico](https://www.raspberrypi.com/documentation/microcontrollers/pico-series.html)

## Watchdog Chip
[Attiny85](https://www.microchip.com/en-us/product/ATtiny85)

## Sensors 

#### [MD0555](https://moderndevice.com/products/wind-sensor-rev-p): Wind Sensor
Protocol: 
<br/>Callibration: 

#### [PT1000](https://microtherm.de/files/microtherm/downloads/mirotherm_PT1000_en.pdf): Temperature
Protocol: 
<br/>Callibration:  

#### [BME680](https://www.adafruit.com/product/3660): Temperature, Pressure, Humidity, Gas, Altitude
Protocol: 
<br/>Callibration:  

#### [Mighty Ohm Geiger Counter](https://mightyohm.com/blog/products/geiger-counter/): CPS 
Protocol: 
<br/>Callibration:  

#### [INA260](https://www.ti.com/product/INA260): current, voltage, power
Protocol: 
<br/>Callibration:  

#### [LSM9DS1](https://www.st.com/en/mems-and-sensors/lsm9ds1.html): 9-axis IMU
Protocol: 
<br/>Callibration:  

#### [MTK3339](https://www.adafruit.com/product/746): GPS
Protocol: 
<br/>Callibration:  

#### [SGP30](https://www.mouser.com/pdfdocs/Sensirion_Gas_Sensors_SGP30_Datasheet_EN-1148053.pdf): Gas Sensor
Protocol: I^2C
<br/>Callibration:
Sensor raw signals are used as inputs for the on-chip calibration and baseline compensation algorithms.
The TVOC and CO2 equivalent are calculated from the sensor signals.
Sensor is 2 data bytes (MSB first) and 1 CRC byte in intervals of 1s for each of two air quality signals.
First 15 seconds is intitialization phase and returns fixed values of TVOC and CO2.

#### [SHT31](https://sensirion.com/media/documents/213E6A3B/63A5A569/Datasheet_SHT3x_DIS.pdf): Humidity, Temperature
Protocol: 
<br/>Callibration:  

#### [ZOPT220](https://www.sparkfun.com/products/retired/14264): UVB Sensor
Protocol: 
<br/>Callibration:  

#### On Board Temperature (connected to on-board ADC)
Protocol: ADC (analog read)
<br/>Callibration: Maybe, probably N/A

## Storages
#### [SD Card](https://www.adafruit.com/product/4682)
Protocol: SPI
