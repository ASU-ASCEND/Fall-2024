#include "PCF8523Sensor.h"

PCF8523Sensor::PCF8523Sensor() {}

bool PCF8523Sensor::begin() {
    return rtc.begin();
}

DateTime PCF8523Sensor::now() {
    return rtc.now();
}

void PCF8523Sensor::adjust(const DateTime& dt) {
    rtc.adjust(dt);
}

void PCF8523Sensor::calibrate() {
    if (!rtc.initialized() || rtc.lostPower()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
}

bool PCF8523Sensor::isRTCReady() {
    return rtc.initialized() && !rtc.lostPower();
}
