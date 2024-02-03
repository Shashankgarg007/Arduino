#include <Arduino.h>

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu =0;
#else 
static const BaseType_t app_cpu =1;
#endif

//static const int led_pin=1;
/*
// Task 1: Blink the LED

void led_blink(void*parameter)
{
  //Run Forever
  while(1)
  {
    digitalWrite(led_pin,HIGH);
    Serial.println("LED is on");
    vTaskDelay(1000/portTICK_PERIOD_MS);
    digitalWrite(led_pin,LOW);
    Serial.println("LED is off");
    vTaskDelay(1000/portTICK_PERIOD_MS);
  }

}
void setup()
{
  Serial.begin(115200);
  while(!Serial);
  pinMode(led_pin,OUTPUT);
  //Create and Run the Task
  xTaskCreatePinnedToCore(led_blink, "LED Blink", 1024, NULL, 1, NULL, app_cpu);
  


}
void loop()
{
//code execution will never reach here

}
*/
const char msg[] = "Sir please aaj to friday hai jaldi chor dijiye";

static TaskHandle_t t1 = NULL;
static TaskHandle_t t2 = NULL;

void print_msg(void *parameter)
{
  int len = strlen(msg);
  while(1)
  {
   Serial.println();
   for(int i=0;i<len;i++)
   {
    Serial.print(msg[i]);
    vTaskDelay(10/portTICK_PERIOD_MS);
   }
   Serial.println();
   vTaskDelay(1000/portTICK_PERIOD_MS);
  }
}

void print_star(void *parameter)
{
  while(1)
  {
    Serial.print("*");
    vTaskDelay(100/portTICK_PERIOD_MS);
  }
}

void setup()
{
  Serial.begin(300);
  vTaskDelay(1000/portTICK_PERIOD_MS);
  Serial.println();
  Serial.println("Task Scheduling");
  Serial.println();
  Serial.println("Task are scheduled using");
  Serial.println(xPortGetCoreID());
  Serial.println();
  Serial.println("with priorities");
  Serial.println(uxTaskPriorityGet(NULL));

  xTaskCreatePinnedToCore(print_msg ,"print msg",1024,NULL,1,&t1,app_cpu);
  xTaskCreatePinnedToCore(print_star,"print star",1024,NULL,2,&t2,app_cpu);


}

void loop()
{
  for(int i=0;i<4;i++)
  {
    vTaskSuspend(t2);
    vTaskDelay(2000/portTICK_PERIOD_MS);
    vTaskResume(t2);
    vTaskDelay(2000/portTICK_PERIOD_MS);
  }

  if(t1!=NULL)
  {
    vTaskDelete(t1);
    t1=NULL;
  }
}




