#ifndef ERROR_DISPLAY_H
#define ERROR_DISPLAY_H

#include <Arduino.h>

#define ERROR_PIN_2 22
#define ERROR_PIN_1 21
#define ERROR_PIN_0 20

/**
 * Error codes, largest will be displayed 
 * Max 7 errors (1 led should always be blinking)
 */
typedef enum {
  CRITICAL_FAIL = 0, // no sensors or no storage
  NO_SD_CARD, 
  LOW_SENSOR_COUNT,
  POWER_CYCLED
} Error;

class ErrorDisplay {

  private:
    int pin_level; 
    Error code; 

    ErrorDisplay(){
      ErrorDisplay::pin_level = 0; 
      pinMode(ERROR_PIN_0, OUTPUT); 
      pinMode(ERROR_PIN_1, OUTPUT); 
      pinMode(ERROR_PIN_2, OUTPUT); 
    }

  public:
    static ErrorDisplay& instance(){
      static ErrorDisplay only_instance; 
      return only_instance; 
    }

    void addCode(Error e){
      if(e < this->code){
        this->code = e; 
      }
    }

    void toggle(){
      this->pin_level = !(this->pin_level);

      uint8_t display_code = 7 - code; // 0 is heightest
      
      digitalWrite(ERROR_PIN_2, this->pin_level && (display_code & 0b100));
      digitalWrite(ERROR_PIN_1, this->pin_level && (display_code & 0b010));
      digitalWrite(ERROR_PIN_0, this->pin_level && (display_code & 0b001));
    }

};


#endif