#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "";
char ssid[] = "";
char pass[] = "";

BlynkTimer timer;
int pinValue = 0;

#define LED1 D1
#define LED2 D2
#define Buzzer D3
#define Sensor D0

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Sensor, INPUT);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000L, notifiaction);
}
BLYNK_WRITE(V0) {
  pinValue = param.asInt();
}

void notifiaction() {
  int sensor = digitalRead(Sensor);
  if (pinValue == 1) {
    Serial.println("System is ON");
    if (sensor == 1) {
      digitalWrite(LED2, HIGH);
      digitalWrite(LED1, LOW);
      digitalWrite(Buzzer, LOW);
    } else if (sensor == 0) {
      Blynk.notify("WARNING! A fire was detected");
      digitalWrite(LED2, LOW);
      digitalWrite(LED1, HIGH);
      digitalWrite(Buzzer, HIGH);
    }
  } else if (pinValue == 0) {
    Serial.println("System is OFF");
  }
}

void loop() {
  Blynk.run();
  timer.run();
} 