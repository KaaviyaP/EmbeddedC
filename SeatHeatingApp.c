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

int main(void)
{
    
    while(1)
    {
        if(activity1()==1) //both the switches are pressed
        {
           
            LED_PORT |= (1<<LED_PIN); //LED ON
            activity2();
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
