#include <Arduino.h>

static const int but_pin = 0;
static const int led_pin = 16 ;
 
static int button_state = HIGH;
static int last_button_state = HIGH;
static unsigned long last_debounce_time = 0;
static unsigned long debounce_delay = 50;
 
void setup()
{
  Serial.begin(115200);
  while(!Serial);
  pinMode(but_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
}
void loop()
{
  int reading = digitalRead(but_pin);

  if(reading!= last_button_state)
  {
    last_debounce_time = millis();

  }
  if((millis() - last_debounce_time) > debounce_delay)
  {
    if(reading != button_state)
    {
      button_state = reading;
      if(button_state == LOW)
      {
        Serial.println("Bhidu Daba Diya re");
      }
    }
  } 
  last_button_state = reading;
}

