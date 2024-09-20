#include "ZOPT220Sensor.h"

ZOPT220Sensor::ZOPT220Sensor() : ZOPT220Sensor(0) {}

ZOPT220Sensor::ZOPT220Sensor(unsigned long minimum_period) 
    : Sensor("ZOPT220", "ZOPTUV(),ZOPTLight(lx),", 2, minimum_period) {}

bool ZOPT220Sensor::verify(){
    return zopt220xSetup();
}

arduino::String ZOPT220Sensor::readData() {
    // UV index
    setResolution(2);
    setGain(4);
    enableUVBSensing();

    // might need delay

    float uvIndex = getUVIndex(); // can be converted to UV Index

    // ALS - Abient Light 
    setResolution(2);
    setGain(1);
    enableALSSensing();

    // might need delay
    int it = 0;
    while(!dataAvailable() && it < 40){
        delay(10);
        it++;
    }

    long als = getALS();

    return String(uvIndex) + ", " + String(als) + ", "; 
}
