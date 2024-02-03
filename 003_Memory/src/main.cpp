#include <Arduino.h>

static const int led_pin = 16;
int led_state = LOW; // global variable for led state

void setup()
{
  Serial.begin(115300);
  while (!Serial); // wait till serial is configured
  pinMode(led_pin, OUTPUT); //led pin is output
}
void loop()
{
  if(Serial.available() == true){
    int cmd = Serial.parseInt(); // read the character from serial
    if(cmd==1){
      led_state = HIGH;
      digitalWrite(led_pin, led_state);
      Serial.println(" LED is off ");
    }
    else if(cmd==2){
      led_state = LOW;
      digitalWrite(led_pin, led_state);
      Serial.println(" LED is on  ");
    }
    else

    {
      Serial.println("Invalid command");
    }

  }
}