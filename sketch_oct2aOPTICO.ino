#include <ESP8266WiFi.h>  // Incluye la librería para ESP-12E

const char* ssid = "Alumnos";    // Nombre de la red Wi-Fi
const char* pass = "";           // Contraseña de la red Wi-Fi (dejar vacío si no tiene)

const int cny70Pin = A0;         // Pin analógico para el CNY70

void setup() {
  Serial.begin(115200);           // Inicia la comunicación serial
  pinMode(cny70Pin, INPUT);       // Configura el pin del CNY70 como entrada
  setupWifi();
}

void loop() {
  int cny70Value = analogRead(cny70Pin); // Lee el valor del sensor CNY70
  Serial.print("CNY70 Value: ");
  Serial.println(cny70Value);     // Imprime el valor del sensor (0 a 1023)
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

