#include "INA260Sensor.h"

INA260Sensor::INA260Sensor() : INA260Sensor(0) {}

INA260Sensor::INA260Sensor(unsigned long minimum_period)
    : Sensor("INA260", "INACurr(mA),INAVolt(mV),INAPow(mW),", 3, minimum_period) {}

bool INA260Sensor::verify() {
    ina260 = Adafruit_INA260();
    return ina260.begin();
}

String INA260Sensor::readData() {
    float current = ina260.readCurrent();
    float busVoltage = ina260.readBusVoltage();
    float power = ina260.readPower();

    return String(current) + ", " + String(busVoltage) + ", " + String(power) + ", ";
}