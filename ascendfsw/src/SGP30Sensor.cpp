#include "SGP30Sensor.h"

SGP30Sensor::SGP30Sensor() : SGP30Sensor(0) {}

SGP30Sensor::SGP30Sensor(unsigned long minimum_period)
    : Sensor("SGP30", "SGPTVOC(ppb), SGPeCO2(ppm), SGPTVOCBase(ppb), SGPeCO2Base(ppb),SGPH2, SGPEtha",
    6, minimum_period) {}

bool SGP30Sensor::verify(){
    return sgp.begin();
}

String SGP30Sensor::readData(){
    String output = "";
    if(sgp.IAQmeasure()){
        output += String(sgp.TVOC) + ", ";
        output += String(sgp.eCO2) + ", ";
    }
    else {
        output += "-, -, ";
    }

    uint16_t TVOC_base, eCO2_base;
    if(sgp.getIAQBaseline(&eCO2_base, &TVOC_base)) {
        output += String(TVOC_base) + ", " + String(eCO2_base) + ", ";
    }
    else {
        output += "-, -, ";
    }

    if(sgp.IAQmeasureRaw()){
        output += String(sgp.rawH2) + ", ";
        output += String(sgp.rawEthanol) + ", ";
    }
    else {
        output += "-, -, ";
    }
    
    return output;
}