#ifndef PCF8523SENSOR_H
#define PCF8523SENSOR_H

#include <RTClib.h>

/** saving? */
class PCF8523Sensor {
public:
    PCF8523Sensor();  
    bool begin();     
    DateTime now();   

private:
    RTC_PCF8523 rtc;  // Private RTC object

    void adjust(const DateTime& dt);  
    void calibrate();                 
    bool isRTCReady();                
};

#endif // PCF8523SENSOR_H
