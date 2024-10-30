#include <SparkFun_AS7331.h>
#include <AS7331Sensor.h>

<<<<<<< HEAD
AS7331Sensor::AS7331Sensor() : AS7331Sensor(0) {}

AS7331Sensor::AS7331Sensor(unsigned long minium_period)
   : Sensor("AS7331", "UVA(nm), UVB(nm), UVC(nm)", 3, minium_period) {}


//verify
bool AS7331Sensor::verify() {
   return myUVSensor.begin(); }


//get data
String AS7331Sensor::readData() {


   myUVSensor.readAllUV();


   float uva = myUVSensor.getUVA();
   float uvb = myUVSensor.getUVB();
   float uvc = myUVSensor.getUVC();
  
   return String(uva) + ", " + String(uvb) + ", " + String(uvc) + ", ";
   
    }
=======

AS7331Sensor::AS7331Sensor() : AS7331Sensor(0) {}


AS7331Sensor::AS7331Sensor(unsigned long minium_period)
    : Sensor("AS7331", "UVA(nm), UVB(nm), UVC(nm)", 3, minium_period) {}

//verify 
bool AS7331Sensor::verify() {
    return myUVSensor.begin(); }

//get data
String AS7331Sensor::readData() { 

    myUVSensor.readAllUV();

    float uva = myUVSensor.getUVA();
    float uvb = myUVSensor.getUVB();
    float uvc = myUVSensor.getUVC();
    
    return String(uva) + ", " + String(uvb) + ", " + String(uvc) + ", ";
     
     }

>>>>>>> main
