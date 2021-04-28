#ifndef __ACTIVITY_3_H__
#define __ACTIVITY_3_H__
/**
 * @file activity3.h
 * @author KaaviyaP (kaaviya2881999@gmail.com)
 * @brief Functions to convert the ADC value to corresponding PWM in activity3
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Macro Definitions
 */
#define PWM_20_PERCENT (205)
#define PWM_40_PERCENT (410)
#define PWM_70_PERCENT (717)
#define PWM_95_PERCENT (973)

/**
 * Include files
 */ 
#include <util/delay.h>
#include <avr/io.h>

/**
 * Function Definitions
 */

/**
 * @brief Initialize Timer1 registers 
 * 
 */
void InitTimer();

/**
 * @brief Produce duty cycle in PWM according to i/p ADC value
 * 
 * @param[in] temp The ADC value from activity2
 */
void activity3_PWM(uint16_t temp);

#endif /* __ACTIVITY_3_H__ */