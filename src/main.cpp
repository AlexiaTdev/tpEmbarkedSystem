#include <Arduino.h>
#define LED 13
#define LED_MASK (1<<5)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led_setup();
  Serial.println("blink");
}

void led_setup() {
  //je ne veux pas utiliser les fonctions arduino
  DDRB |= LED_MASK;
}

void led_toggle(){
  PORTB ^= LED_MASK;
}

void loop() {
  // put your main code here, to run repeatedly:
  led_toggle();
  delay(1000);
}