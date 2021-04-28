#include "activity4.h"

void USARTInit()
{

    // Set baud rate
    UBRR0H = (uint8_t)(UBRR_VALUE>>8);
    UBRR0L = (uint8_t)UBRR_VALUE;
    UCSR0C=(1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ00);
    //Enable the Rx and Tx
    UCSR0B=(1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);
}

int USARTRead()
{

    while(!(UCSR0A &(1<<RXC0)))
    {
        //Do nothing
    }
    return UDR0;
}

void USARTWrite(uint16_t temp)
{
    int data;

    if(temp>=0 && temp<=200){
            data=20;
            while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data;        // Put data into buffer, sends the data
            _delay_ms(2000);
        }
        else if(temp>=210 && temp<=500){
            data=25;
            while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data;        // Put data into buffer, sends the data
            _delay_ms(2000);
        }
        else if(temp>=510 && temp<=700){
            data=29;
            while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data;        // Put data into buffer, sends the data
            _delay_ms(2000);
        }
        else if(temp>=710 && temp<=1024){
             data=33;
             while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data;        // Put data into buffer, sends the data
            _delay_ms(2000);
        }
        else{
            data=0;
            while (!( UCSR0A & (1<<UDRE0)));  // Wait for empty transmit buffer
            UDR0 = data;        // Put data into buffer, sends the data
            _delay_ms(2000);
            
        }
    

}


