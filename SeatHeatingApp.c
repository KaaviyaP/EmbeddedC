/**
 * @file SeatHeatingApp.c
 * @author KaaviyaP
 * @brief Heat Seating Application to set Temperature of seat
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "activity1.h"
#include "activity2.h"
#include "activity3.h"
#include "activity4.h"

int main(void)
{
    uint16_t temp;
    
    while(1)
    {
        if(activity1()==1) //Both the switches are pressed
        {
           
            LED_PORT |= (1<<LED_PIN); //LED ON
            temp=activity2(); //Get the ADC value
            activity3(temp); //PWM output based on temperature
		    USARTWrite(temp); //To Serial monitor to print Temperature
            

        }
        else  //in all other cases
        {
            LED_PORT &= ~(1<<LED_PIN); //LED OFF
		    _delay_ms(200);
        }

    }
    return 0;
}
