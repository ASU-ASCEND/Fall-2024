
#ifndef PCF8523SENSOR_H
#define PCF8523SENSOR_H

#include <RTClib.h>

class PCF8523Sensor {
public:
    PCF8523Sensor();
    bool begin();
    DateTime now();
    void adjust(const DateTime& dt);
    void calibrate();

private:
    RTC_PCF8523 rtc;
};

#endif // PCF8523SENSOR_H
