// Definindo os pinos dos leds
const int ledPin1 = 2;
const int ledPin2 = 3;
const int ledPin3 = 4;
const int ledPin4 = 5;
const int ledPin5 = 6;

// Pino do potenciometro
const int potPin = A0;

// variaveis para armazenar o valor do potenciometro
int potValue = 0;
int previousPotValue = 0;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

void loop() {
  // Leitura do valor do potenciometro
  potValue = analogRead(potPin);

  // mapeando o valor to potenciometro para os numero de leds
  int numLEDs = map(potValue, 0, 1023, 0, 5);

  // Verifica as mudança no numero dos leds a acender
  if (numLEDs != previousPotValue) {
    // Acende ou apaga os leds conforme o novo valor do potenciometro
    for (int i = 2; i <= 6; i++) {
      if (i <= numLEDs + 1) {
        digitalWrite(i, HIGH);  // acende o led
      } else {
        digitalWrite(i, LOW);   // apagar o led
      }
    }
    previousPotValue = numLEDs;  // Atualiza o valor do potenciometro
  }
}
