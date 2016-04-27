/*
  My_Button
 
 Turns on and off a light emitting diode(LED) connected to digital  
 pin 13, when pressing a pushbutton attached to pin 7. 
 
 
 The circuit:
 * onboard LED anode attached from pin 13. LED cathod is connected to ground through series resistor. 
 * External pushbutton on GPIO Board pin named SW4 to Arduino board pin 7.  The other end of push button is connected to ground. 
   When push button is released, Arduino pin 7 is floating.(Not a good way of feeding Logic HIGH)
   When push button is pressed, Arduino pin 7 is Grounded.
  
  Things To Do:
  
   1. Run this program. Check that as long as switch is released, the LED is ON.
   2. When switch is pressed LED become OFF.
   3. Make changes in program so that LED state and switch states are reversed.
   4. There is another but somewhat longer code given at the bottom in commented area. It reads test switch status and appropriately operates on LED.
   4. Write a fresh program which waits until switch is pressed and when it is released, it toggles the LED state from ON to OFF and OFF to ON.
   
   
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 17 Jun 2009
 by Tom Igoe
 modified 1 Jun 2011
 by P W Dandekar
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 7;     // the pin number of the pushbutton pin
const int ledPin =  13;      // the pin number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);     

  digitalWrite(buttonPin, HIGH); // Set input pin to High so that internal 20K to 30K weak pull up is enabled.
                                 // Now floating is converted to proper HIGH voltage state or level.
}

void loop(){
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);// read the voltage on pin 7. It is due to switch. 
  
  //buttonState = buttonState ^ 0x01; // complement LS bit of value stored in var buttonstate 
  
  digitalWrite(ledPin, buttonState);  // dump the value stored in variable buttonState on pin 13.

}


/*

  // check if the pushbutton is reelased. if it is not pressed, the voltage on pin 7 is 5V so make buttonState as HIGH:
  if (buttonState == HIGH) {     
    // turn LED on:    
    digitalWrite(ledPin, HIGH);  
  } 
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW); 
  }


*/

