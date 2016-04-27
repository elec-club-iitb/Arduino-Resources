/*
  AnalogInput_LED_timing
  
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). Note this sketch does not use PWM.
 
    The circuit:
   * LED connected to pin 13. LED anode to pin 13 and LED cathode to ground through a 1 K series resistor.
   * When Pin 13 is LOW, LED becomes OFf. When pin 13 is HIGH, LED becomes ON. 
   * Connect Arduino +5V and Ground pins to General Purpose Input / Output Board +5V and GND pins. Use red wire for +5v and black or green wire for GND.
   * Connect Potentiometer viper POT-1 pin analog input 0. do not connect it to digital pin 0. 
   * one side of potentiometer is connected to 5V and other side to Ground.
 
   Things to do:
 
  1. Run the sketch as it is and see the LED is blinking. 
  2. Turn the pot fully on one side. If analog voltage fed to analog pin is 0 then the 
     LED blinking time period will be very small and blinking rate will be very high and LED will appear steadily but dimly lit. 
     For some values of pot why does it appear steady and dimly lit?
  3. Turn the pot fully on the other side. If analog voltage to pin 0 is 5V then delay will be 1023 ms and LED will blink slowly.
  4. Turn pot gently and see LED blinking rate change.
  5. This is analog input digital frequency output control.

 
 Created by David Cuartielles
 Modified 16 Jun 2009
 By Tom Igoe
 
 Modified by P W dandekar Sept 09, 2013.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 
 */

int sensorPin = 0;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED for Severino
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    // sensorValue may have a value from 0 to 1023.  
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);         // the delay will be 0ms to 1023 ms. 
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);         // the delay will be 0ms to 1023 ms.
}
