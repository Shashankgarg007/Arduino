#include <Arduino.h>

class Flasher{
  int led_pin;
  int led_state;
  unsigned long on_time;
  unsigned long off_time;
  unsigned long last_update;

  public:
  Flasher(int pin, unsigned long ont, unsigned long oft)
  {
  led_pin=pin;
  on_time=ont;
  off_time=oft;
  pinMode(led_pin,OUTPUT);
  led_state=LOW;
  last_update=0;
  }

void update()
{
  if((millis()-last_update)> on_time && led_state==1)
  {
    last_update=millis();
    led_state=!led_state;
    digitalWrite(led_pin,led_state);
    Serial.println("Led is off");
  }
  else if((millis()-last_update)> off_time &&  led_state==0)
  {
    last_update=millis();
    led_state=!led_state;
    digitalWrite(led_pin,led_state);
    Serial.println("Led is on");
  }
}
};

Flasher led1(2,1000,500);
Flasher led2(16,2000,1500);

void setup()
{
  Serial.begin(115200);
  while(!Serial);
  Serial.println("--Led Flasher class--");
}

void loop()
{
  led1.update();
  led2.update();

}