#ifndef __ACTIVITY_4_H__
#define __ACTIVITY_4_H__
/**
 * @file activity4.h
 * @author KaaviyaP (kaaviya2881999@gmail.com)
 * @brief Functions to print the Temperature in Oscilloscope in activity4
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Macro Definitions
 */
#define F_CPU 16000000UL
#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

/**
 * Include files
 */ 
#include <util/delay.h>
#include <avr/io.h>

/**
 * Function Definitions
 */

/**
 * @brief Setting Baud rate and Enabling Rx and Tx 
 * 
 */
void USARTInit();

/**
 * @brief Reading data
 * 
 * @return int The read data
 */
int USARTRead();

/**
 * @brief Writing data to view in serial monitor
 * 
 * @param[in] temp The ADC value
 */
void activity4_USARTWrite(uint16_t temp);

#endif /* __ACTIVITY_4_H__ */