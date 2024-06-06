#include <Servo.h>

//declarando as variaveis do servo motor
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

//variaveis para armazenar os valores do potenciometro
int potValue1;
int potValue2;
int potValue3;
int potValue4;

int serValue1;
int serValue2;
int serValue3;
int serValue4;

void setup(){
  Serial.begin(9600);
  // passando as portas que os servos estão conectados
  servo1.attach(7);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(4);
  delay(1000);
}

void loop(){
   // Leitura dos valores dos potenciômetros 
  // de 0 a 180 para o servomotor 1
  // de 0 a 90 para os servomotores 2 e 4
  // de 0 a 120 para o servomotor 3
  
  potValue1 = analogRead(A5);
  serValue1 = map(potValue1, 0, 1023, 0, 180);
  
  potValue2 = analogRead(A4);
  serValue2 = map(potValue2, 0, 1023, 0, 90);
  
  potValue3 = analogRead(A3);
  serValue3 = map(potValue3, 0, 1023, 0, 120);
  
  potValue4 = analogRead(A2);
  serValue4 = map(potValue4, 0, 1023, 0, 90);
  

  // enviando os valores calculados para os servomotores correspondente
  servo1.write(serValue1);
  servo2.write(serValue2);
  servo3.write(serValue3);
  servo4.write(serValue4);
}