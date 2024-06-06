#include <Servo.h>

// definindo os pinos
const int buttonPin = 2;
const int ledPinRed = 3;
const int ledPinBlue = 4;
const int ledPinYellow = 5;
const int ledPinGreen = 6;
const int ledPinOrange = 7;
const int ledPinBlue2 = 8;
const int servoPin = 9;

Servo servoMotor;

void setup() {
  // configurando os pinos
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);
  pinMode(ledPinYellow, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinOrange, OUTPUT);
  pinMode(ledPinBlue2, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  // inicializando o servo motor
  servoMotor.attach(servoPin);

  servoMotor.write(0);
}

void loop() {
  // Verificando se o botão foi pressionado
  while(digitalRead(buttonPin) == HIGH) {
    // acende o led vermelho e movimenta o servo para 30 graus
    digitalWrite(ledPinRed, HIGH);
    servoMotor.write(30);
    delay(1000);

    // acende o led azul e movimenta o servo para 60 graus
    digitalWrite(ledPinBlue, HIGH);
    servoMotor.write(60);
    delay(1000);

    // acende o led amarelo e movimenta o servo para 90 graus
    digitalWrite(ledPinYellow, HIGH);
    servoMotor.write(90);
    delay(1000);

    // Acende o led verde e movimenta o servo para 140 graus
    digitalWrite(ledPinGreen, HIGH);
    servoMotor.write(140);
    delay(1000);

    // acende o led laranja e movimenta o servo para 180 graus
    digitalWrite(ledPinOrange, HIGH);
    servoMotor.write(180);
    delay(1000);
    digitalWrite(ledPinBlue2, HIGH);
    delay(2000);
    
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinBlue, LOW);
    digitalWrite(ledPinYellow, LOW);
    digitalWrite(ledPinGreen, LOW);
    digitalWrite(ledPinOrange, LOW);
    digitalWrite(ledPinBlue2, LOW);
    servoMotor.write(0);
  }
}