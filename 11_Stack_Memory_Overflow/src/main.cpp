#include <Arduino.h>

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu=0;
#else
static const BaseType_t app_cpu=1;
#endif
//test task
void test_task(void*parameter)
{
  while(1)
  {
  int a=1;
  int b[100];
  for(int i=0;i<100;i++)
  {
    b[i]=a+1  ;
  }
  Serial.println(b[0]);
  Serial.print("High Water Mark (words): ");
  Serial.println(uxTaskGetStackHighWaterMark(NULL));
  Serial.print("Heap before malloc(bytes): ");
  Serial.println(xPortGetFreeHeapSize());
  int *ptr;
  ptr=(int *)pvPortMalloc(1024*sizeof(int));

  for (int i=0;i<1024;i++)
  {
    ptr[i]=3;
  }
  Serial.print("Heap after malloc(bytes): ");
  Serial.println(xPortGetFreeHeapSize());
  vTaskDelay(2000/portTICK_PERIOD_MS);
  }
}
void setup()
{
  Serial.begin(115200);
  vTaskDelay(1000/portTICK_PERIOD_MS);
  Serial.println("Memory Overflow Example");
  //create and run the task
  xTaskCreatePinnedToCore(test_task, "Test Task", 1500, NULL, 1, NULL, app_cpu);

  vTaskDelete(NULL);

}
void loop()
{

}