#include "activity1.h"

void delay_ms(uint32_t delay_time)
{
	uint32_t units = 0;
	for (units = 0; units <= delay_time; units++)
	{
		_delay_ms(1);
	}
}

void peripheral_init(void)
{
	
	DDRB |= (1<<PB0); // set PB0=1 and DDRB as ouput for LED
    DDRD &= ~(1<<PD0); //set as input pin
    PORTD |= (1<<PD0); //set bit PD0 for ButtonSwitch
    DDRD &= ~(1<<PD1); //set as input pin
    PORTD |= (1<<PD1); //set bit PD1 for HeaterSwitch

}

void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}

int activity1(void)
{
    /* Initialize Peripherals */
	peripheral_init();
    
    while(1){
        if(!(PIND&(1<<BUTTON_SENSOR)) && !(PIND&(1<<TEMP_SENSOR))) //both the switches are pressed
        {
            change_led_state(LED_ON);   //LED ON
		    delay_ms(LED_ON_TIME); 

        }
        else if(!(PIND&(1<<BUTTON_SENSOR)) && (PIND&(1<<TEMP_SENSOR))) //ButtonSwitch is pressed but HeaterSwitch is not pressed
        {
            change_led_state(LED_OFF);
		    delay_ms(LED_OFF_TIME);	 //LED OFF

        }
        else if((PIND&(1<<BUTTON_SENSOR)) && !(PIND&(1<<TEMP_SENSOR)))//HeaterSwitch is pressed but ButtonSwitch is not pressed
        {
            change_led_state(LED_OFF);
		    delay_ms(LED_OFF_TIME);	 //LED OFF

        }
        else if((PIND&(1<<BUTTON_SENSOR)) && (PIND&(1<<TEMP_SENSOR)))// both switches are not pressed
        {
            change_led_state(LED_OFF);
		    delay_ms(LED_OFF_TIME);	 //LED OFF

        }

    }
    return 0;
}
