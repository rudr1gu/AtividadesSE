#include <Servo.h>

const int buttonPin = 9;
const int ledPinRed = 3;
const int ledPinGreen = 4;
const int buzzerPin = 5;
const int servoPin = 2;

Servo servoMotor;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Inicialização do servo motor
  servoMotor.attach(servoPin);

  // Posição inicial do servo motor
  servoMotor.write(0);

  // LED vermelho inicialmente aceso
  digitalWrite(ledPinRed, HIGH);
}

void loop() {
  // verifica se o botão foi pressionado
  if (digitalRead(buttonPin) == HIGH) {
    // apaga o led vermelho e acende o led verde
    digitalWrite(ledPinRed, LOW);
    digitalWrite(ledPinGreen, HIGH);
    digitalWrite(buzzerPin, HIGH);

    // movimenta o servo motor para 90graus
    servoMotor.write(90);
    delay(5000);

    // retorna o servo motor para a posição inicial
    servoMotor.write(0);

    digitalWrite(ledPinGreen, LOW);
    digitalWrite(ledPinRed, HIGH);
    digitalWrite(buzzerPin, LOW);

    delay(1000);
  }
}
