#include <IRremote.h>

int RECV_PIN = 8;
long l;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    l = results.value;
    if (l>0x7FF) {l = l- 0x800;}
    
    Serial.println(l, HEX);
    irrecv.resume(); // Receive the next value
  }
}
