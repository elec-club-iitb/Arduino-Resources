/*
 This sketch continiously sends characters over serial port. It begins with character of code 0x20 and sends up to code 0x40.
 There is 0.1 second delay between each character sent which you can change.
 The number of characters sent is displayed on first and second line of LCD.
 The characters sent by Arduino MCU over the USB cable reaches Arduino IDE and it can display it through its Serial Moniotor software.
 Invoke Serial Monitor by pressing Ctrl + Shift + M together.
 Change limit 0x40 to higher value to see more codes sent to printer.
 
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
 
 Created on 22nd July 2010.
 by Prakash W Dandekar
 
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int c, count;

void setup(){
    // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop()
{
  count =0;
  while (count<10000){
    for (c=0x20;c<=0x3F;c++) // send 32 characters starting from ASCII code 0x20 to 0x3F.
    {
      Serial.write(c); // send character in variable c.
      lcd.write(c); // display sent character.
      delay(100);// delay a bit. 
 lcd.clear();     
    }// end of for.
    Serial.write(13); // send carriage return.
    Serial.write(10); // send and line feed.
    count++;//       
  }// end of while.
}// end of loop

/*
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());

  // when characters arrive over the serial port...
  if (Serial.available()) {
    // there is atleast one char received over serial port.
    // read it.
    c = Serial.read();// read incoming character in variable c.
    Serial.write(++c); // send incoming character in variable c.(First increment it before sending).
    lcd.write(c); // display received character.
  }// end of if.

*/

