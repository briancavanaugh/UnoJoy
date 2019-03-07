/*  dataForController_t.h
 *
 *	  Alan Chatham - 2011
 *
 *  This is simply a typedef for a struct
 *   that holds information about controller
 *   button presses.  It is used by the controller
 *   libraries to pass information from an application
 *   to a library function that formats and sends
 *   appropriate controller data
 */

#ifndef DATA_FOR_CONTROLLER_T
#define DATA_FOR_CONTROLLER_T

	typedef struct dataForController_t
	{
		uint8_t buttonXOn : 1;  // variables to abstractly tell us which buttons are pressed		
		uint8_t buttonAOn : 1;
		uint8_t buttonYOn : 1;
		uint8_t buttonBOn : 1;
		uint8_t buttonL1On : 1;
		uint8_t buttonL2On : 1;
		uint8_t l3On : 1;
		uint8_t buttonR1On : 1;
		
		uint8_t buttonR2On : 1;
		uint8_t r3On : 1;
		uint8_t buttonSelectOn : 1;
		uint8_t buttonStartOn : 1;
		uint8_t homeOn : 1;
		uint8_t dpadLeftOn : 1;
		uint8_t dpadUpOn : 1;
		uint8_t dpadRightOn : 1;
		
		uint8_t dpadDownOn : 1;
		uint8_t leftStickX : 8; 
		uint8_t leftStickY : 8;
		uint8_t rightStickX : 8;
		uint8_t rightStickY : 8;
	} dataForController_t;


#endif
