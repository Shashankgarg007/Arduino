#include <Arduino.h>
#define led 2
#define sled 16
void setup()
{
Serial.begin(115200);  //boud rate
while(!Serial); // wait till serial is configured
pinMode(led, OUTPUT); // led pin is output pin
pinMode(sled, OUTPUT); // led pin is output pin
}

void loop(){
  digitalWrite(led, HIGH);
  digitalWrite(sled, LOW);
  Serial.println(" LED 1 is off && LED 2 is on ");
  delay(1000);
  digitalWrite(led, LOW);
  digitalWrite(sled, HIGH);
  Serial.println(" LED 1 is on && LED 2 is off ");
  delay(1000);

}
