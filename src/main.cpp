#include <Arduino.h>
//dht22 sert à alumer le atm
void dht22_send_start() {
    DDRB |= (1<<DDB0);   // je set arduino  en état sortie sur le port DDRB
    PORTB &= ~(1<<DDB0); // je mets la val 0 sur le port 0 de DDRB
    delay(2000);
    PORTB |= (1 << DDB0); // je mets la val 1 sur le port 0 de DDRB
    delayMicroseconds(30);
    DDRB &= ~(1<<DDB0); //je remets l'arduino en écoute
}

void dht22_receive_ack() {
  //PINB & (1<<PINB0) en gros PINB ça va rendre toutes les valeur de chaque bit/ le & c'est une opération bitwise /
  // (1<<PINB0) on mets un 1 au niveau bit0
    while(PINB & (1<<PINB0)) {
      // Transmission des valeurs

    }; 
}

void setup() {
  // put your setup code here, to run once:
  dht22_send_start(); 
}

void loop() {
  // put your main code here, to run repeatedly:
  dht22_receive_ack();
}