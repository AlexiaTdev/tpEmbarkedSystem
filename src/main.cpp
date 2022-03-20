#include <Arduino.h>
#define LED 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("blink");
}

void led_setup() {
  //utilisation du code arduino
  digitalWrite(LED, HIGH);
}

void loop() {
  led_setup();
  delay(1000);
}