/*
 My_Blink
 
 This program or sketch is adapted from original program/sketch created by David Cuartielles and H. Barragan on 1 June 2005
  
 This program blinks an on board LED.
 
 On Severino board, the LEd is connected to pin no. 13.
 On Sanguino board, the LED is connected to pin no 1.
 
 This sketch turns on an LED on for one second, then off for one second, repeatedly.
 
 The circuit:
 * LED connected from digital pin 13 to ground.
 
 * Note: On most Arduino boards, there is already an LED on the board
 connected to pin 13, so you don't need any extra components for this example.
 
 Things to do:
 
  1. Run the sketch as it is and see the LED blink.
  2. Decrease both the delay times by 5 times i.e.make the delay 200 ms in place of 1000 ms. Run the sketch. The LED should blibk 5 times faster.
  3. Now set delay after LED ON to 1000 ms and keep the second delay still as 200 ms. Run the sketch that now LEd blinks slowly as well as it remains ON for most of the time and stays OFF for very small time.
  4. Exchange on and off delays and observe the behavious of LED.
  5. If time permits set both delays to 5000 ms and see how boring it is to watch the LED blink at 1/10 Hz.
 
 
 You may refer further to:  http://arduino.cc/en/Tutorial/Blink
 
 Created by P W Dandekar
 13 July 2010.

 */

//------------------------------Variable Declarations-----------------------------------------

//int ledPin =  13;    // LED connected to digital pin 13
#include "WProgram.h"
void setup();
void loop();
int ledPin =  0;    // LED connected to digital pin 0

// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pin as an output: 
  pinMode(ledPin, OUTPUT);     
  
}// end of setup. 

// the loop() method runs over and over again, as long as the Arduino has power

void loop()                     
{
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(20);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(20);                  // wait for a second
}// end of loop.

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

