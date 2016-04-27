/*
  AnalogInput_PWD_Out
  
 This program reads a 10-bit value from ADC channel 0 and divides it by 4 and sets ot out on PWM channel no. 9.
 Thus we can control the analog voltage output using an analog input signal.
 
 The circuit:
 * Connect Arduino +5V and Ground pins to General Purpose Input / Output Board +5V and GND pins. Use red wire for +5v and black or green wire for GND.
 * connect Potentiometer viper POt-1 pin analog input 0. do not connect it to digital pin 0. 
 * one side of potentiometer is connected to 5V and other side to Ground.
 * Connect arduino PWM output pin 9 to LED0 pin of GPIO board.
   Note that pin LED0 is cathode of LED whose anode is connected to 5V through a 1 K series resistor. 
 * When Pin 9 is LOW, LED becomes ON. When pin 9 is HIGH, LED becomes OFF. 
 * if your Arduino board has ATmega328 MCU then you have 6 PWM channels available - on pins 3,5,6,9,10,11.
 
  Things to do:
 
  1. Run the sketch and see that LEd brightness is dependednt upon the pot setting.
  2. Turn the pot completely clockwise. Depending upon the end of pot connected to 5V, you may get 5V or 0 V on viper. So LED will be full brightness or completely off.
  3. Now turn the pot anti-clockwise. So LED will be full off or fully bright.
  4. now set the pot at intermediate values and see that you get all intermediate values of intensity based on pot setting.  
  
 Created by P W Dandekar
 on 25th July 2010

 
 */

int sensorPin = 0;    // select the input pin for the potentiometer
int pwmPin = 9;      // select the pin for the LED for Severino
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() 
{
  // declare the ledPin as an OUTPUT:
  pinMode(pwmPin, OUTPUT);  
}

void loop() 
{
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  analogWrite( pwmPin, (sensorValue/4)  );// divide the input and put it as output.Why division by 4 was required?
  
  }
  
  
  /*
    // Instead of dividing by 4, we can use a map function to map input value of range 0-1023 to output
    // value range 0 to 255.
    
    sensorValue = map(sensorValue,0,1023,0,255); // old sensorvalue is scaled down and stored back in var sensorvalue
  */
  
  
