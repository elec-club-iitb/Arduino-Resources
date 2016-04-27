/*
  Switch_Transition
 
 This sketch detects low to high transition of switch input and toggles LED on each transition.
 
 
 The circuit:
 * onboard LED anode attached from pin 13. LED cathod is connected to ground through series resistor. 
 * External pushbutton on GPIO Board pin named SW4 to Arduino board pin 7.  The other end of push button is connected to ground. 
   When push button is released, Arduino pin 7 is floating.(Not a good way of feeding Logic HIGH)
   When push button is pressed, Arduino pin 7 is Grounded.
  
  Things To Do:
  
   1. Run this program. Check that LED state is either ON or OFF depending upon internal variable.
   2. When switch is pressed and kept pressed, no change occurs to LED state. 
   3. When pressed switch is released, the LED toggles that is ON become OFF and OFF becomes ON.
   4. See whether your program runs without glitch. If not you need to debounce the switch transition.
   5. Change code so that HIGH to LOW transistion on input causes state change of LED.
  
  
 created on 09 september 2013
 by P W Dandekar
 
 This example code is in the public domain.
 
 */

// constants won't change. They're used here to define pin numbers:
const int buttonPin = 7;     // the pin number of the pushbutton pin
const int ledPin =  13;      // the pin number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int ledState = 0;         // variable for storing LED status. 1 means On and 0 means OFF.
int pastState = 1;        // define a var to store previous condition of switch. 1 means not pressed and 0 means pressed.

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);      // set ledPin as output.
  digitalWrite(ledPin, ledState);  // copy var ledState on LED. initially it is OFF.
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);   
  digitalWrite(buttonPin, HIGH); // Set input pin to High so that internal 20K to 30K weak pull up is enabled.
                                 // Now floating is converted to proper HIGH voltage state or level.
}

void loop(){

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);// read the voltage on pin 7. It is due to switch. 

  // check if the pushbutton was earlier released but now pressed i.e. both conditions are being met. If not then do nothing. 
  // If yes then toggle LED variable and appropriately set LED voltage to HIGH or LOW.
  if ( (pastState == LOW) && (buttonState == HIGH)    ) 
  //if ( (pastState == HIGH) && (buttonState == LOW)    ) 
  { // dump LED var on LED pin. 
    ledState = ledState ^ 0x01  ; // XOR only LS bit of variable with 1 and rest with 0. This toggles only LS bit
    digitalWrite(ledPin, ledState);  // copy var ledState on LED. 
    delay(20);// 20 ms delay for the program to wait till switch stabilizes in next state and bouncing is over.
  } 
  else
  {
    // do nothing. We are keeping this space reserved for future use if any.
  }

  pastState = buttonState; // current state become past state for next iteration.
  delay(100);// a small loop delay inserted so that program does not spin very fast.
  
}// end of loop.




