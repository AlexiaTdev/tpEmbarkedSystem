#include <Arduino.h>
#define LED 13
#define LED_MASK (1<<5)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  clock_setup();
  Serial.println("blink");
}

void clock_setup() {
  //clock prescaler
  TCCR1B |= (1<<0)|(1<<2);
  //mode
  TCCR1A = OCR1A;
  //interrupt
  TIMSK1 =OCIE1A;
}

void led_toggle(){
  PINB = LED_MASK;
}

void loop() {
  // put your main code here, to run repeatedly:
  led_toggle();
  delay(1000);
}