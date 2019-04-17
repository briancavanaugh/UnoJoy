/*
 * typedefs.h
 *
 * Created: 12/13/2011 2:26:51 PM
 *  Author: Alan Chatham
 *
 *	This file contains all the typedef'ed structs we're using to store button data
 */ 


#ifndef PHYSICAL_BUTTON_LIST_T
#define PHYSICAL_BUTTON_LIST_T

// How many total inputs do we have?
#define NUMBER_OF_INPUTS 36
#define NUMBER_OF_DIGITAL_BUTTONS 27

// This one is an abstract representation of what physical buttons we have
//  on the controller itself
typedef struct physicalButtonList_t{
	uint8_t buttonBOn;
	uint8_t buttonAOn;
	uint8_t buttonYOn;
	uint8_t buttonXOn;
	uint8_t buttonL1On;
	uint8_t buttonR1On;
	uint8_t buttonL2On;
	uint8_t buttonR2On;
	uint8_t buttonSelectOn;
	uint8_t buttonStartOn;
	
	uint8_t keypad1On;
	uint8_t keypad2On;
	uint8_t keypad3On;
	uint8_t keypad4On;
	uint8_t keypad5On;
	uint8_t keypad6On;
	uint8_t keypad7On;
	uint8_t keypad8On;
	uint8_t keypad9On;
	uint8_t keypadCOn;
	uint8_t keypad0On;
	uint8_t keypadEOn;
	
	uint8_t dpadUpOn;
	uint8_t dpadDownOn;
	uint8_t dpadLeftOn;
	uint8_t dpadRightOn;
	
	uint8_t leftStickX;
	uint8_t leftStickY;
} physicalButtonList_t;
#endif // PHYSICAL_BUTTON_LIST_T
