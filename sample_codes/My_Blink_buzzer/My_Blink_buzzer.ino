/*
  My_Blink_Buzzer
  This sketch turns on LED and buzzer together on and off repeatedly.
  After you try it out, copy this sketch into another name and make modifications so that LED and buzzer are switched on for diffiernt durations 
  keeping off time as 1000 ms.
 
 
 The circuit:
 * on Arduino board itself, LED anode connected from digital pin 13 and LED cathode is connected to ground through a series resistor to ground.
 * Buzzer +ve connected to pin 12 and buzzer negative to ground. So whenever pin 12 is HIGH, buzzer will sound.  
 * Connect a wire from pin 13 of Arduino to LED 7 on General Purpose I/o Board.
 * Coonect +5V and Ground from Arduino Board to VCC and GND pins on GP I/O Board respectively. Please do not connect reverse polarity. 
 
 1. Note that LED on Arduino Board and LED on GPIO board are inverse of each other. While LED on Arduino and buzzer are in phase.
    This is due to fact that electrical connections of both LEDs are different.
 2. Go on reducing the delay after LED and Buzzer off commands from 1000 ms to 100 ms, 10 ms and 1 msrespectively. 
 3. In some cases, you can hear a small blip on buzzer even for 1 ms on time.
 4. If you want separate delays for buzzer and LED and want them to be done sequentially what changes will you do in code?
 
  This example code is in the public domain.
  
  Created by P W Dandekar on Sept 06, 2013.
  
 */



// note that we are using #define to replace ledPin by 13. This is second way of declaring names which take on values.
#define ledPin 13
#define buzPin 12

void setup() {// this executes only once.                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(ledPin, OUTPUT);     // define ledPin is in  output mode  
  pinMode(buzPin, OUTPUT);     // define buzPin is in  output mode 
}

void loop() {// this executes repeatedly.

  digitalWrite(ledPin, HIGH);   // set the LED on
  digitalWrite(buzPin, HIGH);   // set the buzzer on  
  delay(1);              // wait for some time.  
  
  digitalWrite(ledPin, LOW);    // set the LED off
  digitalWrite(buzPin, LOW);    // set the buzzer off
  delay(1000);              // wait for some time.  
  
}

