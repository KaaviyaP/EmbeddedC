/**
 * @file Activity1_main.c
 * @author KaaviyaP
 * @brief Activity 1 to Turn ON LED if switches for Button sensor and Heator sensor are pressed 
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>
#include <util/delay.h>

/**
 * @brief A main function to turn ON LED if switches for Button sensor and Heator sensor are pressed
 * 
 * @return int 
 */
int main(void)
{

    DDRB |= (1<<PB0); // set PB0=1 and DDRB as ouput for LED
    DDRD &= ~(1<<PD0); //clear bit
    PORTD |= (1<<PD0); //set bit PD0 for ButtonSwitch
    DDRD &= ~(1<<PD1); //clear bit
    PORTD |= (1<<PD1); //set bit PD1 for HeaterSwitch

 while(1){
        if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD1))) //both the switches are pressed
        {
            PORTB |= (1<<PB0); //LED ON

        }
        else if(!(PIND&(1<<PD0)) && (PIND&(1<<PD1))) //ButtonSwitch is pressed but HeaterSwitch is not pressed
        {
            PORTB &= ~(1<<PB0); //LED OFF

        }
        else if((PIND&(1<<PD0)) && !(PIND&(1<<PD1)))//HeaterSwitch is pressed but ButtonSwitch is not pressed
        {
            PORTB &= ~(1<<PB0); //LED OFF

        }
        else if((PIND&(1<<PD0)) && (PIND&(1<<PD1)))// both switches are not pressed
        {
            PORTB &= ~(1<<PB0); //LED OFF

        }

}

    return 0;
}
