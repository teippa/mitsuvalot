#include "sequences.h"

// OUTPUTS AS DIGITAL PINS
#define LED_O3 22 // Oikeanpuoleiset ledit
#define LED_O2 24
#define LED_O1 26
#define LED_K 28  // Ledibar keskellä
#define LED_V1 30 // Vasemmanpuoleiset ledit
#define LED_V2 32
#define LED_V3 34

#define potPin A0 // Potentiometer, blinking speed

#define inPin0 46 // Ledbar control
#define inPin1 48 // Inputs to change programs
#define inPin2 50
#define inPin3 52

/*-------------------------------------------*/

const int leds[] = {LED_O3, LED_O2, LED_O1, LED_K, LED_V1, LED_V2, LED_V3};
const int leds_REUNAT[] = {LED_O3, LED_O2, LED_O1, LED_V1, LED_V2, LED_V3};

const int leds_VASEN[] = {LED_O1, LED_O2, LED_O3}; // Keskeltä ulospäin
const int leds_OIKEA[] = {LED_V1, LED_V2, LED_V3};
const int ledCount = 7;

int tempo_mem = 0;
int globalDelay = 10;


int getTempo() {
  int tempoPinValue = analogRead(potPin); // 0-1023
  //int tempoPinValue =620; // 0-1023

  int maxDelay = 1000;
  int minDelay = 75;
  //int tempo = (maxDelay-minDelay)*(1-tempoPinValue/1023)+minDelay; // 150 - 1000

  return 1023-tempoPinValue+minDelay;
}

void varDelay(int multiplier) {
  globalDelay = getTempo();
  delay(round(globalDelay/multiplier));
}


  


/*#########################################################*/
int getStateWithRands(const int8_t state) {
  int newState = state;
  if (state < 0) {
    newState = random(state, 0) > -1; 
  }
  return state;
}

void setLED_K(int newState) {
  int LED_K_on = digitalRead(inPin0);
  
  newState = newState * LED_K_on;
  digitalWrite(LED_K, newState);
}

void ledsWrite(const int8_t states[7]) {
    digitalWrite(LED_O3, getStateWithRands(states[0]));
    digitalWrite(LED_O2, getStateWithRands(states[1]));
    digitalWrite(LED_O1, getStateWithRands(states[2]));
    setLED_K(getStateWithRands(states[3]));
    digitalWrite(LED_V1, getStateWithRands(states[4]));
    digitalWrite(LED_V2, getStateWithRands(states[5]));
    digitalWrite(LED_V3, getStateWithRands(states[6]));
}
  
void playSequence(const int8_t seq[][7], int currentMode) {
  int seqLen = seq[0][0];
  for (int i=1; i<=seqLen; i++ ) {
    ledsWrite(seq[i]);
    varDelay(1);

    if (currentMode != getMode()) {
      return; // Return if the mode is changed
    }
  }
}


void setup() {
  Serial.begin(9600);
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  
  for (int i=0 ; i<ledCount ; i++) {
    pinMode(leds[i] , OUTPUT);
    digitalWrite(leds[i], LOW);
  }

}



int getMode() {
  int i1 = digitalRead(inPin1);
  int i2 = digitalRead(inPin2);
  int i3 = digitalRead(inPin3);
  
  return i1 + 2*i2 + 4*i3; // 0-7
}

void loop() {
  int mode = getMode();

  //playSequence(ritariAssa);
  //Serial.print(ritariAssa[0][0]);
  
  switch (mode) {
    case(0): //OOO
      playSequence(allOn, mode);
      break;
    case(1): // VOO
      break;
    case(3): // OVO
      playSequence(randSidesMidOn, mode);
      break;
    case(2): // VVO
      playSequence(ritariAssa, mode);
      break;
    case(4): // OOV
      playSequence(randSidesMidBlink, mode);
      break;
    case(5): // VOV
      playSequence(pseudoRandomSides, mode);
      break;
    case(6): // OVV
      playSequence(waterFall, mode);
      break;
    case(7): // VVV
      playSequence(randSidesMidBlink_rarer, mode);
      break;
    default:
      playSequence(allOn, mode);
      break; 
  }
}
