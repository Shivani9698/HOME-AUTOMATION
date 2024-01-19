#define BLYNK_TEMPLATE_ID "TMPL36a_ZUDO6"
#define BLYNK_TEMPLATE_NAME "HOME AUTOMATION"
#define BLYNK_AUTH_TOKEN "eNjIjpM38fJQSqFWpYc-7c08UWN_OJy_"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "FTTHBSNL";
char pass[] = "29915693";

BlynkTimer timer;

BLYNK_WRITE(V0) {
  int pinValue = param.asInt();
  Serial.println(pinValue);
  if (param.asInt() == 1)
    digitalWrite(D5, HIGH); // For ESP8266, use "D2" instead of just "2"
  else
    digitalWrite(D5, LOW);
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D5, OUTPUT); // For ESP8266, use "D2" instead of just "2"
}

void loop() {
  Blynk.run();
  timer.run();
  delay(2000);
}
