/*
 My_Blink
 
 This program or sketch is adapted from original program/sketch created by David Cuartielles and H. Barragan on 1 June 2005
  
 This program blinks an on board LED.
 
 * Note: On most Arduino boards, there is already an LED on the board  connected to pin 13, so you don't need any extra components for this example.
 
   On Uno,Severino & Dumilanove board, the LED is connected to pin no. 13.
   On Sanguino board, the LED is connected to pin no 1.
 
 This sketch turns on an LED on for one second, then off for one second, repeatedly.
 
 The circuit:
 * LED anode connected from digital pin 13 and LED cathode is connected to ground through a series resistor to ground.
 
 Things to do:
 
  1. Run the sketch as it is and see the LED blink.
  2. Decrease both the delay times from 1000 ms to 200 ms. Compile and run the sketch. The LED should blink 5 times faster but with 50% duty cycle.
  3. Now set delay after LED OFF to 1000 ms. Reduce the delay after ON condition from 1000 ms to 100 ms to 10 ms and at last to 1 ms and see its effect on LED blinking.
  4. Exchange on and off delays and observe the behavious of LED.
  5. If time permits set both delays to 5000 ms and see how boring it is to watch the LED blink at 1/10 Hz.
 
 
 You may refer further to:  http://arduino.cc/en/Tutorial/Blink
 
 Created by P W Dandekar
 13 July 2010.

 */

//------------------------------Variable Declarations-----------------------------------------

int ledPin =  13;    // LED connected to digital pin 13
// #define ledPin 13 // This is another way of giving a name to pin 13. 



// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pin as an output: 
  pinMode(ledPin, OUTPUT);     
  
}// end of setup. 

// the loop() method runs over and over again, as long as the Arduino has power

void loop()                     
{
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(1000);                  // wait for a second
}// end of loop.
