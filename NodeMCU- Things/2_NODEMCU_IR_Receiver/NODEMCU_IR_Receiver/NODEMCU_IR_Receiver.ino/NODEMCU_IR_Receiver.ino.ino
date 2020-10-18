/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremoteESP8266.h>

int RECV_PIN = 4;
int LED1 = 5;
int LED2 =16;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(115200);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value,HEX);
   
   if(results.value == 0x51E43D1B)
    {
      Serial.println("LED1 ON");
      digitalWrite(LED1, HIGH);
    }
    if(results.value == 0xAB91951F)
    {
      Serial.println("LED1 OFF");
      digitalWrite(LED1, LOW);
    }
   if(results.value == 0xFF9186B7)
    {
      Serial.println("LED2 ON");
      digitalWrite(LED2, HIGH);
    }
    if(results.value == 0x8C22657B)
    {
      Serial.println("LED2 OFF");
      digitalWrite(LED2, LOW);
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
