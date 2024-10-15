
#define HEARTBEAT_PIN_0 3
#define HEARTBEAT_PIN_1 4
#define RESET_PIN 0

volatile bool beat0 = 0;
volatile bool beat1 = 0; 

ISR(PCINT0_vect){
  if(digitalRead(HEARTBEAT_PIN_0) == HIGH){
    beat0 = true; 
  }
  if(digitalRead(HEARTBEAT_PIN_1) == HIGH){
    beat1 = true; 
  }
}

void setup(){
  // setup 
  pinMode(HEARTBEAT_PIN_0, INPUT); 
  pinMode(HEARTBEAT_PIN_1, INPUT); 
  pinMode(RESET_PIN, OUTPUT); 
  digitalWrite(RESET_PIN, LOW); 

  // any logical change interrupt 
  MCUCR &= ~((1<<ISC01)|(1<<ISC00));
  MCUCR |= (1<<ISC00);
  // enable Pin Change interrupt 
  GIMSK |= (1<<PCIE); 
  // enable SREG, I think the arduino sdk will do that 

  // enable pins 
  PCMSK |= (1<<PCINT3)|(1<<PCINT4); 

  delay(10000); // wait 10s to start checking
}

void loop(){

  delay(5000); // check every 5s
  if((beat0 || beat1) == false){ // if either beat hasn't changed 
    // one of the tasks if frozen, reset
    digitalWrite(RESET_PIN, HIGH); 
    delay(500); 
    digitalWrite(RESET_PIN, LOW);
    delay(5000); // give the pico time to setup again 
    // clear beats
  }
  beat0 = false;
  beat1 = false;

}
