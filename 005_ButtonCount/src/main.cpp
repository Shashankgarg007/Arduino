#include <Arduino.h>

//pins
static const int but_pin = 0;
 //globals
 static int button_state =HIGH;
 static int last_button_state = HIGH;
 static unsigned long last_debounce_time = 0;
 static unsigned long debounce_delay =0;
 static int count = 0;
 static bool but_flag = 0;
 static unsigned long last_press= 0;
{
  int reading = digitalRead(but_pin);
  if(reading!=last_button_state)
  {
    last_debounce_time = millis();

  }
  if((millis()- last_debounce_time)>debounce_delay)
  {
    if(reading!=button_state)
    {
      button_state=reading;
      if(button_state)
    }
  }
}