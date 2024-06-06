#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define LED_VERDE 4
#define LED_AZUL 5
#define LED_AMARELO 6
#define LED_VERMELHO 7
#define BUZZER_PIN 8

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  if (distance >= 10 && distance < 15) {
    // Distância entre 10cm e 15cm: acende o LED verde
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER_PIN);
  } else if (distance >= 15 && distance < 20) {
    // Distância entre 15cm e 20cm: acende o LED azul
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER_PIN);
  } else if (distance >= 20 && distance < 25) {
    // Distância entre 20cm e 25cm: acende o LED amarelo
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER_PIN);
  } else if (distance >= 25) {
    // Distância maior ou igual a 25cm: acende o LED vermelho e emite um sinal sonoro com o buzzer
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, HIGH);
    tone(BUZZER_PIN, 1000);
    delay(1000);
    noTone(BUZZER_PIN);
    delay(1000);
  } else {
    // Se a distância não se encaixar em nenhuma das faixas, todos os LEDs e o buzzer são desligados
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER_PIN);
  }

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(100);
}
