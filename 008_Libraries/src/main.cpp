#include <Arduino.h>
#include "Button.h"

uint8_t buttonPin;
void setup()
{
  Serial.begin(115200);
  while(!Serial);
  uint8_t button_Pin = init(0, INPUT_PULLUP);

}

void loop()

{
  uint8_t c = readButton(buttonPin);
  if (c!=0)
  {
    Serial.print("Final Count is: ");
    Serial.println(c);
    
  }
}