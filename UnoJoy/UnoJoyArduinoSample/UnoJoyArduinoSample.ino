#include "Keypad.h"
#include "UnoJoy.h"

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
{'1','2','3'},
{'4','5','6'},
{'7','8','9'},
{'*','0','#'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the kpd
byte colPins[COLS] = {12, 11, 10}; //connect to the column pinouts of the kpd
bool keyState[13];

Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
////////////////////////////////////////////////////////////////

const byte BUTTON_ROWS = 4; //four rows
const byte BUTTON_COLS = 4; //four columns
char buttons[BUTTON_ROWS][BUTTON_COLS] = {
{'Q','W','E','R'},
{'A','S','D','F'},
{'Z','X','C','V'},
{'T','Y','U','I'}
};
byte buttonRowPins[BUTTON_ROWS] = {A0,A1,A2,A3}; //connect to the row pinouts of the kpd
byte buttonColPins[BUTTON_COLS] = {2, 3, 4, 5 }; //connect to the column pinouts of the kpd
bool buttonState[17];

Keypad buttonMatrix = Keypad( makeKeymap(buttons), buttonRowPins, buttonColPins, BUTTON_ROWS, BUTTON_COLS );
//////////////////////////////////////////////////////////////////////

void setup(){
  setupPins();
  setupUnoJoy();

  for (int i=0; i<=12; i++){
    keyState[i] = false;
  }
  for (int i=0; i<=15; i++){
    buttonState[i] = false;
  }
}

void loop(){
  // Always be getting fresh data
  dataForController_t controllerData = getControllerData();
  setControllerData(controllerData);
}

void setupPins(void){
  // Set all the digital pins as inputs with the pull-up enabled
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
  
  if (kpd.getKeys())
  {
    for (int i = 0; i < LIST_MAX; i++) // Scan the whole keypad.
    {
      if ( kpd.key[i].stateChanged )   // Only find keys that have changed state.
      {
        switch (kpd.key[i].kstate) {
          case PRESSED:
            switch (kpd.key[i].kchar){
              case '1':
              keyState[1] = true;
              break;
              case '2':
              keyState[2] = true;
              break;
              case '3':
              keyState[3] = true;
              break;
              case '4':
              keyState[4] = true;
              break;
              case '5':
              keyState[5] = true;
              break;
              case '6':
              keyState[6] = true;
              break;
              case '7':
              keyState[7] = true;
              break;
              case '8':
              keyState[8] = true;
              break;
              case '9':
              keyState[9] = true;
              break;
              case '*':
              keyState[10] = true;
              break;
              case '0':
              keyState[11] = true;
              break;
              case '#':
              keyState[12] = true;
              break;
            }
            break;
          case RELEASED:
            switch (kpd.key[i].kchar){
              case '1':
              keyState[1] = false;
              break;
              case '2':
              keyState[2] = false;
              break;
              case '3':
              keyState[3] = false;
              break;
              case '4':
              keyState[4] = false;
              break;
              case '5':
              keyState[5] = false;
              break;
              case '6':
              keyState[6] = false;
              break;
              case '7':
              keyState[7] = false;
              break;
              case '8':
              keyState[8] = false;
              break;
              case '9':
              keyState[9] = false;
              break;
              case '*':
              keyState[10] = false;
              break;
              case '0':
              keyState[11] = false;
              break;
              case '#':
              keyState[12] = false;
              break;
            }
            break;
        }
      }
    }
  }

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (buttonMatrix.getKeys())
  {
    for (int i = 0; i < LIST_MAX; i++) // Scan the whole keypad.
    {
      if ( buttonMatrix.key[i].stateChanged )   // Only find keys that have changed state.
      {
        switch (buttonMatrix.key[i].kstate) {
          case PRESSED:
            switch (buttonMatrix.key[i].kchar){
              case 'Z':
              buttonState[1] = true;
              break;
              case 'X':
              buttonState[2] = true;
              break;
              case 'A':
              buttonState[3] = true;
              break;
              case 'S':
              buttonState[4] = true;
              break;
              case 'C':
              buttonState[5] = true;
              break;
              case 'V':
              buttonState[6] = true;
              break;
              case 'D':
              buttonState[7] = true;
              break;
              case 'F':
              buttonState[8] = true;
              break;
              case 'Q':
              buttonState[9] = true;
              break;
              case 'W':
              buttonState[10] = true;
              break;
              case 'T':
              buttonState[11] = true;
              break;
              case 'Y':
              buttonState[12] = true;
              break;
              case 'U':
              buttonState[13] = true;
              break;
              case 'I':
              buttonState[14] = true;
              break;
            }
            break;
          case RELEASED:
            switch (buttonMatrix.key[i].kchar){
              case 'Z':
              buttonState[1] = false;
              break;
              case 'X':
              buttonState[2] = false;
              break;
              case 'A':
              buttonState[3] = false;
              break;
              case 'S':
              buttonState[4] = false;
              break;
              case 'C':
              buttonState[5] = false;
              break;
              case 'V':
              buttonState[6] = false;
              break;
              case 'D':
              buttonState[7] = false;
              break;
              case 'F':
              buttonState[8] = false;
              break;
              case 'Q':
              buttonState[9] = false;
              break;
              case 'W':
              buttonState[10] = false;
              break;
              case 'T':
              buttonState[11] = false;
              break;
              case 'Y':
              buttonState[12] = false;
              break;
              case 'U':
              buttonState[13] = false;
              break;
              case 'I':
              buttonState[14] = false;
              break;
            }
            break;
        }
      }
    }
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

  controllerData.buttonBOn = buttonState[1];
  controllerData.buttonAOn = buttonState[2];
  controllerData.buttonYOn = buttonState[3];
  controllerData.buttonXOn = buttonState[4];
  controllerData.buttonL1On = buttonState[5];
  controllerData.buttonR1On = buttonState[6];
  controllerData.buttonL2On = buttonState[7];
  controllerData.buttonR2On = buttonState[8];
  controllerData.buttonSelectOn = buttonState[9];
  controllerData.buttonStartOn = buttonState[10];
  controllerData.dpadUpOn = buttonState[11];
  controllerData.dpadDownOn = buttonState[12];
  controllerData.dpadLeftOn = buttonState[13];
  controllerData.dpadRightOn = buttonState[14];
  controllerData.keypad1On = keyState[1];
  controllerData.keypad2On = keyState[2];
  controllerData.keypad3On = keyState[3];
  controllerData.keypad4On = keyState[4];
  controllerData.keypad5On = keyState[5];
  controllerData.keypad6On = keyState[6];
  controllerData.keypad7On = keyState[7];
  controllerData.keypad8On = keyState[8];
  controllerData.keypad9On = keyState[9];
  controllerData.keypadCOn = keyState[10];
  controllerData.keypad0On = keyState[11];
  controllerData.keypadEOn = keyState[12];
  
  // Set the analog sticks
  //  Since analogRead(pin) returns a 10 bit value,
  //  we need to perform a bit shift operation to
  //  lose the 2 least significant bits and get an
  //  8 bit number that we can use  
//  controllerData.leftStickX = analogRead(A0) >> 2;
//  controllerData.leftStickY = analogRead(A1) >> 2;
//  controllerData.rightStickX = analogRead(A2) >> 2;
//  controllerData.rightStickY = analogRead(A3) >> 2;

  // And return the data!
  return controllerData;
}
