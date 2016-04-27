/*   
  Motor Control Shield_2_IR
  
  This sketch uses a special shield designed by embeddedmarket.com / Technido which drives 2 DC motors and can read 4 IR sensors for Line following robot.
  This sketch tests the IR sensors.   The shield connects to 4 sensor boards, each board having an IR emitter (clear LED) and a IR detector or 
  phototransistor (dark device). The clear device or IR emitters are powered by 5V and usually show a forward drop of about 1.2V in forward direction.
  The detector or receiver converts IR energy falling on it into current passing through a 1 M ohms resistor. Higher IR energy means more current 
  through 1 Mega ohm resistor. If there is no energy, there is no current and voltage across 1 M resistor is cloase to 0V. 
  The voltage across resistor detector voltage is compared with a threshold voltage set by potentiometer. If detector voltage exceeds 
  threshold (higher IR energy or white h line) then comparator output is logic 0 and
  LED wired on output will become ON. The comparator output is also wired to one Arduino digital pin.
  
  
  Circuit:
  
  D10 - Comparator output due to sensor wired to connector JP22 and pot R11
  D11 - Comparator output due to sensor wired to connector JP20 and pot R7
  D12 - Comparator output due to sensor wired to connector JP23 and pot R9
  D13 - Comparator output due to sensor wired to connector JP24 and pot R12
  
 
  Originaly written by P W Dandekar in June 2013, modified on 01 October 2015.
 
 */
 

#define  IR1   10
#define  IR2   11
#define  IR3   12
#define  IR4   13

void setup() {
  // set up 4 IR pins as inputs.
  pinMode(IR1, INPUT);   
  pinMode(IR2, INPUT);   
  pinMode(IR3, INPUT);   
  pinMode(IR4, INPUT);   

  Serial.begin(9600);// 
  Serial.println("IR sensor test program begins.....");// sent starting message to serial monitor.
  delay (2000);// wait for 2 seconds.
 
}

void loop() {
  int s1,s2,s3,s4;// define vars to hold sensor status ---  0 = more IR energy and LED off , 1 = dark or less IR energy and LED on
  // Read status of all 4 sensors in 4 variables.
  s1 = digitalRead(IR1);
  s2 = digitalRead(IR2);
  s3 = digitalRead(IR3);
  s4 = digitalRead(IR4);
  // Send this data to serial port for viewing...
  
  // If there is no reflecting surface in front of the sensors then there will be less or no energy falling on detector 
  // and the comparator output will be 1 and its LED will be off.
  Serial.print("Sensor on JP22 = ");
  Serial.print(s1);
  Serial.print("  Sensor on JP20 = ");
  Serial.print(s2);
  Serial.print("  Sensor on JP23 = ");
  Serial.print(s3);
  Serial.print("  Sensor on JP24 = ");
  Serial.println(s4);
  
  // Put a white surface like a paper or visiting card in front of  sensors. This increases sensor current, comparator output becomes 0
  // and the LED becomes ON.
  
  delay(1000);// wait here for 1 second  

}// end of main

