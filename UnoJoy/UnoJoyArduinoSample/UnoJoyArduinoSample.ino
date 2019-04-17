
#include "UnoJoy.h"

void setup(){
  setupPins();
  setupUnoJoy();
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Set all the digital pins as inputs
  // with the pull-up enabled, except for the 
  // two serial line pins
  for (int i = 2; i <= 12; i++){
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }
  pinMode(A0, INPUT);
  digitalWrite(A0, HIGH);
  pinMode(A1, INPUT);
  digitalWrite(A1, HIGH);
  pinMode(A2, INPUT);
  digitalWrite(A2, HIGH);
  pinMode(A3, INPUT);
  digitalWrite(A3, HIGH);
  pinMode(A4, INPUT);
  digitalWrite(A4, HIGH);
  pinMode(A5, INPUT);
  digitalWrite(A5, HIGH);
}

dataForController_t getControllerData(void){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // Since our buttons are all held high and
  //  pulled low when pressed, we use the "!"
  //  operator to invert the readings from the pins
  controllerData.buttonBOn = !digitalRead(2);
  controllerData.buttonAOn = !digitalRead(3);
  controllerData.buttonYOn = !digitalRead(4);
  controllerData.buttonXOn = !digitalRead(5);
  controllerData.buttonL1On = !digitalRead(6);
  controllerData.buttonR1On = !digitalRead(7);
  controllerData.buttonL2On = !digitalRead(8);
  controllerData.buttonR2On = !digitalRead(9);
  
  controllerData.buttonSelectOn = !digitalRead(10);
  controllerData.buttonStartOn = !digitalRead(11);
  controllerData.dpadUpOn = !digitalRead(A0);
  controllerData.dpadDownOn = !digitalRead(A1);
  controllerData.dpadLeftOn = !digitalRead(A2);
  controllerData.dpadRightOn = !digitalRead(A3);
  controllerData.keypad1On = !digitalRead(2);
  controllerData.keypad2On = !digitalRead(3);
  
  controllerData.keypad3On = !digitalRead(4);
  controllerData.keypad4On = !digitalRead(5);
  controllerData.keypad5On = !digitalRead(6);
  controllerData.keypad6On = !digitalRead(7);
  controllerData.keypad7On = !digitalRead(8);
  controllerData.keypad8On = !digitalRead(9);
  controllerData.keypad9On = !digitalRead(10);
  controllerData.keypadCOn = !digitalRead(11);
  
  controllerData.keypad0On = !digitalRead(12);
  controllerData.keypadEOn = !digitalRead(A0);
  
  // Set the analog sticks
  //  Since analogRead(pin) returns a 10 bit value,
  //  we need to perform a bit shift operation to
  //  lose the 2 least significant bits and get an
  //  8 bit number that we can use  
  controllerData.leftStickX = analogRead(A0) >> 2;
  controllerData.leftStickY = analogRead(A1) >> 2;
  controllerData.rightStickX = analogRead(A2) >> 2;
  controllerData.rightStickY = analogRead(A3) >> 2;
  // And return the data!
  return controllerData;
}
