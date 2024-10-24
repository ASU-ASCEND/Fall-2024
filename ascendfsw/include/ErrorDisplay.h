#ifndef ERROR_DISPLAY_H
#define ERROR_DISPLAY_H

#include <Arduino.h>

#define ERROR_PIN_2 22
#define ERROR_PIN_1 21
#define ERROR_PIN_0 20

/**
 * Error codes:
 * Smallest will be displayed as the binary value 7 - (enum value) 
 * ex. CRITICAL_FAIL (enum value of 0) will be all 3 leds blinking (7 - 0 = 7 or 0b111)
 * Max 7 errors (1 led should always be blinking)
 * NONE will always be 1
 */
typedef enum {
  CRITICAL_FAIL = 0,  // no sensors or no storage
  NO_SD_CARD,         // triggered if SD card verify function returns false or if an SD card write fails
  LOW_SENSOR_COUNT,   // triggered for less than 5 sensors verified 
  POWER_CYCLED,       // determined based on if there are multiple data files on the SD card 
  NONE                // default state, lowest priority 
} Error;

/**
 * @brief Singleton class for the 3 GPIO LED Error Display 
 * 
 */
class ErrorDisplay {

  private:
    int pin_level; 
    Error code; 

    ErrorDisplay(){
      this->pin_level = 0; 
      this->code = NONE; 
      pinMode(ERROR_PIN_0, OUTPUT); 
      pinMode(ERROR_PIN_1, OUTPUT); 
      pinMode(ERROR_PIN_2, OUTPUT); 
    }

  public:
    /**
     * @brief Accesses the only instance of ErrorDisplay (Singleton)
     * 
     * @return ErrorDisplay& Instance of ErrorDisplay 
     */
    static ErrorDisplay& instance(){
      static ErrorDisplay only_instance; 
      return only_instance; 
    }

    /**
     * @brief Sets the error code to the given value if the given error is of a higher priority then the current error
     * 
     * @param e The error code to display 
     */
    void addCode(Error e){
      if(e < this->code){
        this->code = e; 
      }
    }

    /**
     * @brief Toggles the level of the error display 
     * 
     */
    void toggle(){
      this->pin_level = !(this->pin_level);

      uint8_t display_code = 7 - code; // 0 is heightest

      if(this->code == Error::NONE) display_code = 0b001; 
      
      digitalWrite(ERROR_PIN_2, this->pin_level && (display_code & 0b100));
      digitalWrite(ERROR_PIN_1, this->pin_level && (display_code & 0b010));
      digitalWrite(ERROR_PIN_0, this->pin_level && (display_code & 0b001));
    }

};


#endif