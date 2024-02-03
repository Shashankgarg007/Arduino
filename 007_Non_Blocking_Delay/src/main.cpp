#include <Arduino.h>

static const int led_pin=2;
static unsigned long led_state=0;
static unsigned long on_time=1000;
static unsigned long off_time=1000;
static unsigned long last_update=0;

void setup()
{
  Serial.begin(115200);
  while(!Serial);
  pinMode(led_pin,OUTPUT);

}
void loop()
{
  if((millis()-last_update)> on_time && led_state==1)
  {
    last_update=millis();
    led_state=0;
    digitalWrite(led_pin,led_state);
    Serial.println("Led is off");
  }
  else if((millis()-last_update)> off_time &&  led_state==0)
  {
    last_update=millis();
    led_state=1;
    digitalWrite(led_pin,led_state);
    Serial.println("Led is on");
  }

}
