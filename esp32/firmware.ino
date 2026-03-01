#include <WiFi.h>
#include <PubSubClient.h>

/* ------------ WiFi Config ------------ */
const char* ssid     = //"Your SSID"
const char* password = //"Your PASSWORD"

/* ------------ MQTT Config ------------ */
const char* mqtt_server = "     ";   // Your PC IP
const int   mqtt_port   = 1883;
const char* mqtt_topic  = "home/sensors";

/* ------------ Pins ------------ */
#define PIR_PIN   27     // PIR digital pin
#define SOIL_PIN  34     // Soil moisture ADC pin (ADC1 only)

/* ------------ Objects ------------ */
WiFiClient espClient;
PubSubClient client(espClient);

/* ------------ Functions ------------ */
void setup_wifi();
void reconnect_mqtt();

/* ------------ Setup ------------ */
void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);

  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
}

/* ------------ Main Loop ------------ */
void loop() {
  if (!client.connected()) {
    reconnect_mqtt();
  }
  client.loop();

  /* Read sensors */
  int pirValue  = digitalRead(PIR_PIN);   // 0 or 1
  int soilValue = analogRead(SOIL_PIN);   // 0–4095

  /* Create JSON payload */
  String payload = "{";
  payload += "\"pir\":";
  payload += pirValue;
  payload += ",";
  payload += "\"soil\":";
  payload += soilValue;
  payload += "}";

  /* Publish */
  client.publish(mqtt_topic, payload.c_str());

  Serial.println(payload);

  delay(2000);  // send every 2 seconds
}

/* ------------ WiFi ------------ */
void setup_wifi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
}

/* ------------ MQTT Reconnect ------------ */
void reconnect_mqtt() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect("ESP32_Node1")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}
