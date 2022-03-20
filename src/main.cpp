#include <Arduino.h>
#define LED 13
#define LED_MASK (1<<5)
#define CS_PRESCALER_1024 ((1<<CS10) | (1<<CS12))
#define TICKS_IN_SECOND 15625
void led_setup() {
  //je ne veux pas utiliser les fonctions arduino
  DDRB |= LED_MASK;

}
void clock_setup() {
    //clock prescaler
  TCCR1A = 0; //WGM11 et WGM1O à 0
    //mode
  //TCCR1B = (1<<0) | (1<<2) | (1<<3); //WGM13 à 0, WGM12 à 1, CS1à à 1, CS11 à 0, CS12 à 1
  //la meme   TCCR1A = (1<<CS10) | (1<<CS12) | (1<<WGM12); 
  //la meme   TCCR1A = CS_PRESCALER_1024 | (1<<WGM12); 
  TCCR1B = CS_PRESCALER_1024 | (1<<WGM12); 
    // valeur a comparer
  // je prends 15625 je le mets en binaire  0B 0011 1101 0000 1001 . Je voudrais ne garder que 0000 1001 pour le low.
  //il faut le caster en Uint8_t ça récupère que la partie à droite
  //OCR1AL = (uint8_t) (TICKS_IN_SECOND & 0xFF);
  //OCR1AH = (uint8_t) (TICKS_IN_SECOND & (0xFF << 8)) >>8;    la meme   OCR1AH = (uint8_t) (TICKS_IN_SECOND & 0xFF00);
  OCR1A = TICKS_IN_SECOND;
    //interrupt
  TIMSK1 = (1 << OCIE1A);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  led_setup();
  clock_setup();
  Serial.println("blink");
}

void led_toggle(){
  PINB = LED_MASK;
}

ISR(TIMER1_COMPA_vect) {
  led_toggle();
}

void loop() {
  // put your main code here, to run repeatedly:
  //led_toggle();
  delay(10000);
  TCCR1B &= ~(CS_PRESCALER_1024);
  delay(10000);
  TCCR1B |= (CS_PRESCALER_1024);
}