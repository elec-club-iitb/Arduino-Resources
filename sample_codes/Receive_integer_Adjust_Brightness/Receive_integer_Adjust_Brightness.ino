/*
  Receive_Integer_Adjust_Brightness
 
 Demonstrates the sending data from the computer to the Arduino board which in this case is used to control the brightness of an LED.  
 The data is sent in 3 individual characters or bytes, each of which ranges from 000 to 255.  It is presumed that 3 digits will be sent necessarily.
 If less than 3 digits are sent then synchronization is lost. If you wish to send 2 then you must send 002. 
 
 Arduino reads these 3 bytes and converts them into an integer and uses them to set the brightness of the LED. The analog output or PWM output pin is connected to LED cathode.
 Sending 000 gives minimum duty cycle and maximum brightness.
 Sending 255 gives maximum duty cycle and minimum brightness.

 
 The circuit:
 LED cathode attached from digital pin 9 to ground.
 LED anode connected to 5V through series resistor.
 Serial connection to Processing, Max/MSP, or another serial application
 
 created 2006
 by David A. Mellis
 modified 14 Apr 2009
 by Tom Igoe and Scott Fitzgeral
 
 Modified by P W Dandekar on 4th July 2011.
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/Dimmer
 
 What happens when 
 
 */
char u,t,h,sum;

const int ledPin = 9;      // the pin that the LED is attached to

void setup()
{
  // initialize the serial communication:
  Serial.begin(9600);
  // initialize the ledPin as an output:
  pinMode(ledPin, OUTPUT);
  u = t = h = sum =0;// clear all variables.
}

void loop() {
  byte brightness;

  // check if data has been sent from the computer:
  if (Serial.available()>2) { // do nothing until 3 digits have been received.
    h = Serial.read() -48;// first digit represent hundreds
    t = Serial.read()-48;// second digit represent tens
    u = Serial.read()-48;// first digit represent units
    sum = h *100 + t* 10 + u ;// add 3 digits with proper weightage to form a number between 0 to 255.
    if (sum >255) { sum =255;}// sum must never exceed 255
    
    // set the brightness of the LED:
    analogWrite(ledPin, sum);
  }
}

