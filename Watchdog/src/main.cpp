#include <Arduino.h>

// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(4, HIGH); 
  delay(1000); 
  digitalWrite(4, LOW); 
  delay(1000); 
}
