#include <ESP8266WiFi.h>  // Cambiar a ESP8266WiFi.h para ESP-12E

const char* ssid = "Alumnos";    // Nombre de la red Wi-Fi
const char* pass = "";           // Contraseña de la red Wi-Fi (dejar vacío si no tiene)

const int mq2Pin = A0;           // Pin analógico del MQ2

void setup() {
  Serial.begin(115200);
  pinMode(mq2Pin, INPUT);         // Configura el pin del MQ2 como entrada
  setupWifi();
}

void loop() {
  int mq2Value = analogRead(mq2Pin); // Lee el valor del sensor MQ2
  Serial.print("MQ2 Value: ");
  Serial.println(mq2Value);         // Imprime el valor del sensor
  delay(500);                     // Espera medio segundo
}

void setupWifi() {
  WiFi.begin(ssid, pass);            // Inicia la conexión Wi-Fi
  Serial.print("Connecting to Wi-Fi");
  
  // Espera hasta que se conecte al Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());    // Muestra la IP local asignada
}
