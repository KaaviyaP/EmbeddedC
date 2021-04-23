# Activity 1 In Action

|OFF|OFF|OFF|ON|
|:--:|:--:|:--:|:--:|
|![OFF](https://user-images.githubusercontent.com/80662569/115880845-cb579200-a468-11eb-8c5f-c0a4af578e13.PNG) |![OFF](https://user-images.githubusercontent.com/80662569/115880893-d5799080-a468-11eb-9b5c-994641382343.PNG)|![OFF](https://user-images.githubusercontent.com/80662569/115880899-d6aabd80-a468-11eb-96f0-ede2b16d1dfb.PNG)|![ON](https://user-images.githubusercontent.com/80662569/115880895-d6122700-a468-11eb-9f96-7bf86424943e.PNG)|


## Activity 1 Code 
```
	#include <avr/io.h>
#include <util/delay.h>

int main(void)
{

    DDRB |= (1<<PB0); // set PB0=1 for LED
    DDRD &= ~(1<<PD0); //clear bit
    PORTD |= (1<<PD0); //set bit PD0 for SeatSwitch
    DDRD &= ~(1<<PD1); //clear bit
    PORTD |= (1<<PD1); //set bit PD0 for HeaterSwitch

 while(1){
        if(!(PIND&(1<<PD0)) && !(PIND&(1<<PD1))) //both the switches are pressed
        {
            PORTB |= (1<<PB0); //LED ON

        }
        else if(!(PIND&(1<<PD0)) && (PIND&(1<<PD1))) //SeatSwitch is pressed but HeaterSwitch is not pressed
        {
            PORTB &= ~(1<<PB0); //LED OFF

        }
        else if((PIND&(1<<PD0)) && !(PIND&(1<<PD1)))//HeaterSwitch is pressed but SeatSwitch is not pressed
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

```
