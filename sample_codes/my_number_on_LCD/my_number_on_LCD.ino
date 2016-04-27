/*
my_number_on_LCD

This sketch displays 3 types of variables on LCD display.

-First is a char or byte type. Th evalue is treated as ASCII code and its image is displayed. e.g. code of 48 will diosplay '0' on LCD, 49 will display '1' and so on.
-Second is an integer and its value is displayed as it is.
-Third is a float and only 2 places after decimal are displayed by default.

Just to show some activity, the variables are incremented every 1 second and displayed again. 
The char variable is treated as ASCII code and its corresponding character image is displayed.
Integer variable is shown its value.
flat variable is incremented by a small increment and displayed.

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 25 July 2009
 by David A. Mellis
 modified by P W Dandekar on 11 sept 2013
 
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12,11, 5, 4, 3, 2);
char k = 32;
int p = 152;
float j = 123.456;// 6 of 456 is not displayed because standard print commands show only 2 places after decimal.
void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("My number Displayed");// note that the message is longer is 16 character space on display so last alphabets get chopped off.
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  lcd.print(k);// print value of var p.
  
  // set the cursor to column 3, line 1
  lcd.setCursor(3, 1);
  lcd.print(p);
  
  // set the cursor to column 6, line 1
  lcd.setCursor(8, 1);
  lcd.print(j);
  
  // now increment all variables for some activity.
  
  k = k+1;
  if (k> 'z') 
  {// if k goes beyond teh ascii code of z then roll it back to 32 or code for space character.
    k=32;
  }
  
  p = p+1;
  j = j+0.01 ; //a very small increment
  
  delay (1000);// wait for some time before redisplaying again.
  
}

