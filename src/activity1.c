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
	
	DDRD |= (1<<PD2); // set PB0=1 for LED
    DDRD &= ~(1<<PD0); //clear bit
    PORTD |= (1<<PD0); //set bit PD0 for SeatSwitch
    DDRD &= ~(1<<PD1); //clear bit
    PORTD |= (1<<PD1); //set bit PD0 for HeaterSwitch


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
       
        if(!(PIND&(1<<BUTTON_SENSOR )) && !(PIND&(1<<TEMP_SENSOR))) //both the switches are pressed
        {
            LED_PORT |= (1<<LED_PIN); //LED ON
		    delay_ms(LED_ON_TIME); 

        }
        else  //in all other cases
        {
            LED_PORT &= ~(1<<LED_PIN); //LED OFF
		    delay_ms(LED_OFF_TIME);	 

        }

    }
    return 0;
}
