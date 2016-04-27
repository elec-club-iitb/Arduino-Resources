/*

    Read_pots_Display_LCD_serial
    
This program  will read from two ADC channels and store in one int variable at a time.
The data is a value between 0 to 1023.
This value is then displayed on LCD and sent on serial port to be displayed on PC using a Serial Monitor program.


 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * Connect Arduino +5V and Ground pins to General Purpose Input / Output Board +5V and GND pins. Use red wire for +5v and black or green wire for GND.
 * Connect POT-1 pin analog input 0. Do not connect it to digital pin 0. 
 * Connect POT-2 pin analog input 1. Do not connect it to digital pin 1. 
 
 
 created by P. W Dandekar on 24th May 2010.
 modified on sept 10, 2013
 
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int i;
int firstPotPin = 0;
int secondPotPin = 1;

void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Both Pot values......");// note that the message is longer is 16 character space on display so last alphabets get chopped off.
  // initialize the serial communications:
  Serial.begin(9600);
  Serial.println(" Potentiometer values displayed here...");//
  delay(1000);// delay of 1 second just for fun.
  
}// end of setup.

void loop() {
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Both Pot value......");// note that the message is longer is 16 character space on display so last alphabets get chopped off.
  Serial.print(" Potmeter values pot 1 = ");//

  // Read analog value from first potentiometer
  i = analogRead(firstPotPin);
  lcd.setCursor(0, 1);//  // set the cursor to column 0, line 1
  lcd.print(i);// display first pot value.
  Serial.print(i);// send actual value of first pot to PC.

  // Read analog value from first potentiometer
  i = analogRead(secondPotPin);
  lcd.setCursor(8, 1);//   // set the cursor to column 8, line 1
  lcd.print(i);// display first pot value.
  Serial.print("   pot 2 = ");//
  Serial.println(i);// send actual value of second pot to PC.do not forget to send Cr and LF for newline.


  delay(300);
}

  

