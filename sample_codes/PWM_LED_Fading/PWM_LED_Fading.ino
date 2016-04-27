/*
 PWM_LED_fading
 
  This sketch is adapted from example sketch called Fading.
 
  It first increases the duty cycle number from 0 to 255 slowly. This will cause LED intensity to grow slowly. Then it waits for a while so intensity is constant.
  Next it dims the intensity of the LED slowly.then again it waits for sometime. Thus it creates a trapezoidal profile of intensity with time.   
  Thise cycle repeats infinitely.
  
  
   The circuit:
   * LED connected from digital pin 9 to pin LED1 on General Purpose I/O Board. 
     Note that pin LED1 is cathode of LED whose anode is connected to 5V through a 1 K series resistor. 
   * When Pin 9 is LOW, LED becomes ON. When pin 9 is HIGH, LED becomes OFF. 
   * If pin 9 remains LOW for a longer duration ( low duty cycle) then there is more current through LED and higher brightness
   * If pin 9 remains HIGH for a longer duration ( high duty cycle) then there is lesser current through LED and lower brightness   
   * if your Arduino board has ATmega328 MCU then you have 6 PWM channels available - on pins 3,5,6,9,10,11.
 
   Things to do:
 
  1. Run the sketch as it is and see the LED intensity fade in and out. 
  2. Increase the delay time from 30 ms to 100 ms and then to 300 ms. the cycle time will correspondingly increase but you can see the happening more clearly. 
  3. Change the maximum value from 255 to 128. Now the max brightness reached is lesser. Similarly increase the minimum value from 0 to 64. and see its effect.
  4. Change the step from 5 to 10 or reduce it to 1 and see its effect. Lesser value will give it smooth variation. 
  
  
 Created by P W Dandekar
 13 July 2010.

 */

//------------------------------Variable Declarations-----------------------------------------
  int max_limit = 255;  // maximum value upto which PWM value will be set.
  int min_limit = 0;    // maximum value upto which PWM value will be set.
  int pwm_step = 5;     // step size determines quantum of increment or decrement. 
  int d_count   = 30;   // this many milliseconds will be wasted in every step.
  int ledPin = 9  ;// LED is conencted to pin 9 PWM channel.
  int pwm_value;    // var used to set up value to PWM channel that willd ecide LED intensity. 0 means minimum and 255 means max.  
  


void setup() 

{                
  pinMode(ledPin, OUTPUT);  // set pin 9 as output.
}

void loop()                     
{
   
  // We will increase the voltage  to LED from min to max value in steps of pwm_step
  // If LED anode is connected to this voltage then its intensity will decrease as voltage increases.
  
  for ( pwm_value = min_limit; pwm_value<= max_limit; pwm_value= pwm_value+ pwm_step )
  {
    analogWrite(ledPin,pwm_value);  // i increases from 0 to 255 every 200 ms. 
    delay(d_count);        // wait for d_count ms
  }
  
  // Now keep it steady for 3 seconds.
  delay(3000);        // wait for 200 milliseconds.

  // now repeat the process by reducing voltage from max value to  min value in steps of pwm_step
  for ( pwm_value = max_limit; pwm_value >= min_limit; pwm_value= pwm_value - pwm_step )
  {
    analogWrite(ledPin,pwm_value);  // i increases from 0 to 255 every 200 ms. 
    delay(d_count);        // wait for d_count ms
  }
  
  // Now keep it steady for 3 seconds.
  delay(3000);        // wait for 200 milliseconds.

 
}// end of loop.
