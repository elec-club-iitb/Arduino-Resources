/*
  Simple Arduino Server Echo 
 
 This sketch waits for a character to be typed on PC's keyboard (follwed by enter in Arduino Monitor). 
 Then it increments each character by 1 and returns it back to PC.
 So if we type 1234 on keyboard then what we see echoed back is 2345 - each character incremented by one.
 Modify code such that it adds 2 in place of 1 to each character received and sends it.
 
 The circuit:  No external hardware needed.
 
 created June 11, 2011
 by P W Dandekar 
 */

char c;// temporary storage variable declared for use.

void setup() 
{ 
  Serial.begin(9600); 

  // prints title with ending line break 
  Serial.println("Simple Arduino Server Echo"); // print a nice welcoming sentence.
} 

void loop() 
{ 
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // there is atleast one char received over serial port.
    // read it.
    c = Serial.read();// read incoming character in variable c.
    c = c+1; // increment character.
    Serial.write(c); // send incremented value back to PC
  }// end of if.  
} // end of sketch.
