#include <Arduino.h>

#define TRIGGER_PIN 13
#define ECHO_PIN 12 // Asignando el pin 12 para la señal de eco

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration, distance_mm;
  
  // Generar un pulso de 10 microsegundos en el pin TRIGGER
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Leer el tiempo de eco en el pin ECHO
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Convertir el tiempo de eco a distancia en milímetros
  distance_mm = duration * 0.034 * 10 / 2;
  
  // Imprimir la distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance_mm);
  Serial.println(" mm");
  
  delay(1000); // Esperar un segundo antes de tomar otra medida
}
