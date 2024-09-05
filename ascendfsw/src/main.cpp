#include <Arduino.h>
#include <atomic>
#include <queue>
#include "pico/stdlib.h" // use picosdk multicore queue

#include "Sensor.h"
// include sensor headers here

// helper function definitions
int verifySensors(); 

// Global variables
// Sensor arrays
Sensor* sensors[] = {}; 
const int sensors_len = sizeof(sensors) / sizeof(sensors[0]);
bool sensors_verify[sensors_len];
// loop counter 
int it = 0; 


/**
 * @brief Setup for core 0
 *
 */
void setup() {
  // start serial
  Serial.begin(115200); 
  delay(5000); // wait for 5 seconds to ensure serial is initialized 

  // verify sensors
  if(verifySensors() == 0){
    Serial.println("All sensor communications failed");
    while(1) Serial.println("Error"); 
  }
  else {
    Serial.println("At least one sensor works, continuing"); 
  }

  // build csv header
  String header = "Millis, "; 
  for(int i = 0; i < sensors_len; i++){
    if(sensors_verify[i]){
      header += sensors[i]->getSensorCSVHeader(); 
    }
  }
  Serial.println(header); 

}

/**
 * @brief Loop for core 0
 *
 */
void loop() {
  it++;
  Serial.print("it: " + String(it) + "\t");

  // build csv row
  String csv_row = String(millis()) + ", "; 
  for(int i = 0; i < sensors_len; i++){
    csv_row = sensors[i]->getDataCSV(); 
  }
  Serial.println(csv_row); 


}

/**
 * @brief Verifies each sensor by calling each verify() function
 * 
 * @return int, the number of verified sensors
 */
int verifySensors(){
  int count = 0; 
  for(int i = 0; i < sensors_len; i++){
    sensors_verify[i] = sensors[i]->verify(); 
    if(sensors_verify[i]) count++; 
  }
  Serial.println("Pin Verification Results:");
  for (int i = 0; i < sensors_len; i++){
    Serial.print(sensors[i]->getSensorName());
    Serial.print(": ");
    Serial.println(sensors_verify[i] ? "Successful in Communication" : "Failure in Communication (check wirings and/ or pin definitions in the respective sensor header file)");
  }
  Serial.println();

  return count; 
}

/**
 * @brief Setup for core 1
 *
 */
void setup1() {
  
}

/**
 * @brief Loop for core 1
 *
 */
void loop1() {}
