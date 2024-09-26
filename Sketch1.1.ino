//#include "WiFi.h"


const char* ssid = "Alumnos";
const char* pass = "";

const int mq2Pin = 34; // Pin analógico del MQ2 (A0)

void setup() {
  Serial.begin(115200);
  pinMode(mq2Pin, INPUT); // Configura el pin del MQ2 como entrada
  setupWifi();
}

void loop() {
  int mq2Value = analogRead(mq2Pin); // Lee el valor del sensor MQ2
  Serial.print("MQ2 Value: ");
  Serial.println(mq2Value); // Imprime el valor del sensor
  delay(10000); // Espera 10 segundos
}

void setupWifi() {
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
}