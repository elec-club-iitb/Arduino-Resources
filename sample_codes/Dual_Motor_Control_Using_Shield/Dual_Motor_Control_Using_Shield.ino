/*   
  Dual_Motor Control_Using_Shield 
  
  This sketch uses a specialshield designed by embeddedmarket.com which drives 2 DC motors and can read 4 IR sensors for Line following robot.
  The shield provides 3 lines per motor - two directional deciding and one magnitude selecting
  
  This sketch runs two motors , one by one to demo individual control. It runs left motor in one direction from zero to full speed. 
  Then it brings down speed back to zero slowly. It repeats the same for right motor. It runs a trapezoidal speed vs time profile, 
  very common in transportaion.  The whole sequence takes about 10 to 12 seconds per motor depending upon the delay set.
  
  Then it runs the same sequence in which both motors run up to full speed and then come down.
  
  Circuit:
  
  First motor is connected between two pins marked Motor1 
  Second motor is connected between two pins marked Motor2
  
  + terminal should be connected to power supply for motors , in our case VIN(12V) since we are using 12V Dc motors
  - terminal should be connected to motor power supply which is same as ground in Arduino
  
  Motor 1 connections:(already made internally)  
  Enable or PWM input - D3 (PWM)
  Direction input I1  - D2
  Direction input I2  - D4
  CW - I1 = D2 = 1; I2 = D4 = 0; Enable D3 = 1 or PWM 
  CW - I1 = D2 = 1; I2 = D4 = 0; Enable D3 = 1 or PWM 
  STOP - I1 = D2 = x; I2 = D4 = x; Enable D3 = 0 
    
  Motor 2 connections:(already made internally)
  Enable or PWM input - D5 (PWM)
  Direction input I1  - D7
  Direction input I2  - D8
  CW - I1 = D7 = 1; I2 = D8 = 0; Enable D5 = 1 or PWM 
  CW - I1 = D7 = 1; I2 = D8 = 0; Enable D5 = 1 or PWM 
  STOP - I1 = D7 = x; I2 = D8 = x; Enable D5 = 0 
 
  
  Buzzer - D6
  Switch - D9
 
  Originaly written by P W Dandekar in June 2011, modified on 30 Sept 2015.
 
 */
 
// Motor 1 control pins defined here
#define  M1_IN1   2
#define  M1_IN2   4
#define  M1_EN    3
// Motor 2 control pins defined here
#define  M2_IN1   7
#define  M2_IN2   8
#define  M2_EN    5

#define buzzer 6  // define buzzer and switch though they do not have much use here.
#define sw 9

#define d_count 50  // this defines delay in milliseconds between two speed increment or decrement

void setup() {
  // set up 4 PWM output pins used in motor driver in output mode.This is not mandatory
  pinMode(M1_IN1, OUTPUT);   
  pinMode(M1_IN2, OUTPUT);   
  pinMode(M1_EN, OUTPUT);   
  pinMode(M2_IN1, OUTPUT);   
  pinMode(M2_IN2, OUTPUT);   
  pinMode(M2_EN, OUTPUT);   
  pinMode(buzzer, OUTPUT);   
  pinMode(sw, INPUT);    

  digitalWrite(M1_IN1, LOW);// set all 4 direction signals to 0 or passive , both motor stops
  digitalWrite(M1_IN2, LOW);
  digitalWrite(M2_IN1, LOW);
  digitalWrite(M2_IN2, LOW);
  analogWrite(M1_EN,0);// Motor 1 enable = 0 to stop motor 1
  analogWrite(M2_EN,0);// Motor 1 enable = 0 to stop motor 2

  Serial.begin(9600);// 
  Serial.println("2 Motor Bidirectional speed profile demo starting up...");// sent starting message to serial monitor.
  delay (2000);// wait for 2 seconds.
 
}

void loop()   int i;
  
//---------------------------------------LEFT MOTOR ALONE -------------------------------------------------------------------------------

  Serial.println("Motor1 CW Increasing Speed...");// sent current state message to serial monitor.

  // Run Motor1 in Clockwise (CW) direction from 0 to 255 PWM value ( 0 to 100%) INCREASING SPEED
  
  digitalWrite(M1_IN1, HIGH);// set IN1 = High and IN2 = LOW for CW
  digitalWrite(M1_IN2, LOW);
  for (i=0;i<=255;i++) // rising speed in CW direction
  {  // set PWM pulse width from 0 to 255 in steps of 1.
    analogWrite(M1_EN,i);// set PWM value i on M1_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF
  
  Serial.println("Motor1 CW decreasing Speed...");// sent current state message to serial monitor.

  // Run Motor1 in Clockwise (CW) direction from 255 to 0 PWM value ( 100% to 0%) DECREASING SPEED
  for (i=255;i>=0;i--) // falling speed in CW direction
  {  // set PWM pulse width from 255 to 0 in steps of 1.
    analogWrite(M1_EN,i);// set PWM value i on M1_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF
  

//----------------------------------------------------------------------------------------------------------------------

  Serial.println("Motor1 CCW Increasing Speed...");// sent current state message to serial monitor.

  // Run Motor1 in Counter-Clockwise (CCW) direction from 0 to 255 PWM value ( 0 to 100%) INCREASING SPEED
  digitalWrite(M1_IN1, LOW);// set IN1 = LOW and IN2 = HIGH for CCW
  digitalWrite(M1_IN2, HIGH);
  for (i=0;i<=255;i++) // rising speed in CCW direction
  {  // set PWM pulse width from 0 to 255 in steps of 1.
    analogWrite(M1_EN,i);// set PWM value i on M1_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF
  
  Serial.println("Motor1 CCW Decreasing Speed...");// sent current state message to serial monitor.
  
  // Run Motor1 in Counter-Clockwise (CCW) direction from 255 to 0 PWM value ( 100% to 0%) DECREASING SPEED
  for (i=255;i>=0;i--) // falling speed in CCW direction
  {  // set PWM pulse width from 255 to 0 in steps of 1.
    analogWrite(M1_EN,i);// set PWM value i on M1_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF
  
  
  //---------------------------------------RIGHT MOTOR ALONE -------------------------------------------------------------------------------
  Serial.println("Motor2 CW Increasing Speed...");// sent current state message to serial monitor.
 
  // Run Motor2 in Clockwise (CW) direction from 0 to 255 PWM value ( 0 to 100%) INCREASING SPEED
  digitalWrite(M2_IN1, HIGH);// set IN1 = High and IN2 = LOW for CW
  digitalWrite(M2_IN2, LOW);

  for (i=0;i<=255;i++) // rising speed in CW direction
  {  // set PWM pulse width from 0 to 255 in steps of 1.
    analogWrite(M2_EN,i);// set PWM value i on M2_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF
  Serial.println("Motor2 CW Decreasing Speed...");// sent current state message to serial monitor.
  
  // Run Motor2 in Clockwise (CW) direction from 255 to 0 PWM value ( 100% to 0%) DECREASING SPEED
  for (i=255;i>=0;i--) // falling speed in CW direction
  {  // set PWM pulse width from 255 to 0 in steps of 1.
    analogWrite(M2_EN,i);// set PWM value i on M2_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF
  

//----------------------------------------------------------------------------------------------------------------------
  Serial.println("Motor2 CCW Increasing Speed...");// sent current state message to serial monitor.

  // Run Motor2 in Counter-Clockwise (CCW) direction from 0 to 255 PWM value ( 0 to 100%) INCREASING SPEED
  digitalWrite(M2_IN1, LOW);// set IN1 =  LOW and IN2 = HIGH for CCW
  digitalWrite(M2_IN2,HIGH );

  for (i=0;i<=255;i++) // rising speed in CCW direction
  {  // set PWM pulse width from 0 to 255 in steps of 1.
    analogWrite(M2_EN,i);// set PWM value i on M2_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF
  
   Serial.println("Motor2 Motor CCW Decreasing Speed...");// sent current state message to serial monitor.
 
  // Run Motor2 in Counter-Clockwise (CCW) direction from 255 to 0 PWM value ( 100% to 0%) DECREASING SPEED
  for (i=255;i>=0;i--) // falling speed in CCW direction
  {  // set PWM pulse width from 255 to 0 in steps of 1.
    analogWrite(M2_EN,i);// set PWM value i on M2_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF



  //---------------------------------------BOTH MOTORs TOGETHER -------------------------------------------------------------------------------
  Serial.println("Both Motors CW Increasing Speed...");// sent current state message to serial monitor.

  // Run Both Motors in Clockwise (CW) direction from 0 to 255 PWM value ( 0 to 100%) INCREASING SPEED
  digitalWrite(M1_IN1, HIGH);// set IN1 = High and IN2 = LOW for CW
  digitalWrite(M1_IN2, LOW);
  digitalWrite(M2_IN1, HIGH);// set IN1 = High and IN2 = LOW for CW
  digitalWrite(M2_IN2, LOW);

  for (i=0;i<=255;i++) // rising speed in CW direction
  {  // set PWM pulse width from 0 to 255 in steps of 1.
    analogWrite(M1_EN,i);// set PWM value i on M1_EN.
    analogWrite(M2_EN,i);// set PWM value i on M2_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF

  Serial.println("Both Motors CW Decreasing Speed...");// sent current state message to serial monitor.
  
  // Run Left Motor in Clockwise (CW) direction from 255 to 0 PWM value ( 100% to 0%) DECREASING SPEED
  for (i=255;i>=0;i--) // falling speed in CW direction
  {  // set PWM pulse width from 255 to 0 in steps of 1.
    analogWrite(M1_EN,i);// set PWM value i on M1_EN.
    analogWrite(M2_EN,i);// set PWM value i on M2_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  digitalWrite(buzzer, HIGH);// set buzzer ON
  delay(1000);// wait here for 1 second
  digitalWrite(buzzer, LOW);// set buzzer OFF
  

//----------------------------------------------------------------------------------------------------------------------
  Serial.println("Both Motors CCW Increasing Speed...");// sent current state message to serial monitor.

  // Run Both Motors in Counter-Clockwise (CCW) direction from 0 to 255 PWM value ( 0 to 100%) INCREASING SPEED
  digitalWrite(M1_IN1, LOW);// set IN1 = LOW  and IN2 = HIGH for CCW
  digitalWrite(M1_IN2, HIGH );
  digitalWrite(M2_IN1, HIGH);// set IN1 = LOW and IN2 = HIGH for CCW
  digitalWrite(M2_IN2, LOW);
  
  for (i=0;i<=255;i++) // rising speed in CCW direction
  {  // set PWM pulse width from 0 to 255 in steps of 1.
    analogWrite(M1_EN,i);// set PWM value i on M1_EN.
    analogWrite(M2_EN,i);// set PWM value i on M2_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  delay(1000);// wait here for 1 second
  
    Serial.println("Both Motors CCW Decreasing Speed...");// sent current state message to serial monitor.

  // Run Both Motors in Counter-Clockwise (CCW) direction from 255 to 0 PWM value ( 100% to 0%) DECREASING SPEED
  for (i=255;i>=0;i--) // falling speed in CCW direction
  {  // set PWM pulse width from 255 to 0 in steps of 1.
    analogWrite(M1_EN,i);// set PWM value i on M1_EN.
    analogWrite(M2_EN,i);// set PWM value i on M2_EN.
    delay(d_count);// wait for this many ms after each increment.     
  }// end of for loop. 
  
  Serial.println("Complete sequence done.");// sent current state message to serial monitor.

  delay(1000);// wait here for 1 second  

}// end of main

