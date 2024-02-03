#include "Button.h"

uint8_t button_state;
uint8_t last_button_state;
unsigned long last_debounce_time = 0;
unsigned long debounce_delay = 50;
uint8_t count = 0;
bool but_flag =0;
unsigned long last_press = 0;
uint8_t final_count;

// function for button initialization
uint8_t init(uint8_t pin, uint8_t mode)
{
    volatile uint8_t but_pin = pin;
    pinMode(but_pin, mode);
    return but_pin;
}
uint8_t readButton(uint8_t but_pin)
{
    final_count = 0;
    uint8_t reading =digitalRead(but_pin);

    if(reading!= last_button_state)
    {
        last_debounce_time = millis();

    }
    if ((millis()-last_debounce_time)> debounce_delay)
    {
        if (reading!=button_state)
    {
        button_state =reading;
        if (button_state==LOW)
        {
            but_flag=1;
            count++;
            last_press =millis();


        }
    }
    }
    if (but_flag)
    {
        if ((millis()-last_press)>1000)
        {
            final_count=count;
            count=0;
            but_flag=0;

        }
    }
    last_button_state = reading;
    return final_count;
}

