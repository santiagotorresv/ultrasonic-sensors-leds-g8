#include <Arduino.h>

const int trigPin = 5;
const int echoPin = 18;

const int ledVerde = 25;
const int ledAmarillo = 26;
const int ledRojo = 27;

float medirDistancia() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    long duracion = pulseIn(echoPin, HIGH, 30000);

    if (duracion == 0) {
        return -1;
    }

    return duracion * 0.0343 / 2;
}

void apagarLeds() {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarillo, LOW);
    digitalWrite(ledRojo, LOW);
}

void parpadearLed(int led) {
    for (int i = 0; i < 3; i++) {
        digitalWrite(led, HIGH);
        delay(150);

        digitalWrite(led, LOW);
        delay(150);
    }
}

void parpadearTodos() {
    for (int i = 0; i < 3; i++) {
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledAmarillo, HIGH);
        digitalWrite(ledRojo, HIGH);

        delay(150);

        apagarLeds();

        delay(150);
    }
}

void setup() {
    Serial.begin(115200);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);

    pinMode(ledVerde, OUTPUT);
    pinMode(ledAmarillo, OUTPUT);
    pinMode(ledRojo, OUTPUT);

    apagarLeds();
}

void loop() {
    float distancia = medirDistancia();

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    apagarLeds();

    if (distancia > 0 && distancia <= 5) {
        // 0 - 5 cm: ROJO
        parpadearLed(ledRojo);
    }
    else if (distancia <= 15) {
        // 6 - 15 cm: AMARILLO
        parpadearLed(ledAmarillo);
    }
    else if (distancia <= 25) {
        // 16 - 25 cm: VERDE
        parpadearLed(ledVerde);
    }
    else {
        // Más de 25 cm: TODOS
        parpadearTodos();
    }
}