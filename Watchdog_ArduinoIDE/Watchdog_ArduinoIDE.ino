
#define DATA_HEARTBEAT_PIN 3
#define STORAGE_HEARTBEAT_PIN 4
#define RESET_PIN 0

volatile bool data_beat = 0;
volatile bool storage_beat = 0; 

// void PCINT0_ISR(void){

// }

void setup(){
  // setup 
  // pinMode(DATA_HEARTBEAT_PIN, INPUT); 
  // pinMode(STORAGE_HEARTBEAT_PIN, INPUT); 
  pinMode(RESET_PIN, OUTPUT); 
  // digitalWrite(RESET_PIN, LOW); 
}

void loop(){

  delay(10000); 
  digitalWrite(RESET_PIN, HIGH); 
  delay(1000); 
  digitalWrite(RESET_PIN, LOW); 
  // // any logical change interrupt 
  // MCUCR &= ~(0b11);
  // MCUCR |= (0b01);
  // // enable Pin Change interrupt 
  // GIMSK |= (1<<5); 
  // // enable pins PCINT 1 and 0
  // PCMSK |= (1<<0)|(1<<1); 
  
  // // loop 
  // while(1){
  //   delay(10000); // check every 10s 
  //   if((data_beat && storage_beat) == false){
  //     // one of the tasks if frozen, reset
  //     digitalWrite(RESET_PIN, HIGH); 
  //     delay(100); 
  //     digitalWrite(RESET_PIN, LOW);
  //   }
  //   // clear beats
  //   data_beat = false;
  //   storage_beat = false; 
  // }

}
