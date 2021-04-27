#ifndef __ACTIVITY_1_H__
#define __ACTIVITY_1_H__
/**
 * @file activity1.h
 * @author KaaviyaP (kaaviya2881999@gmail.com)
 * @brief User defined utilities, to define pins and ports to Blink an LED ON/OFF in activity1
 * @version 0.1
 * @date 2021-04-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */


/**
 * Macro Definitions
 */
#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */

#define LED_ON_TIME     (200)  /**< LED ON time in milli seconds  */
#define LED_OFF_TIME    (200)   /**< LED OFF time in milli seconds */

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */
#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN  (PORTB0)   /**< LED Pin number  */
#define SENSOR  (PORTD)   /**< Sensors */
#define BUTTON_SENSOR  (PORTD0)   /**< Port for Button Sensor  */
#define TEMP_SENSOR  (PORTD1)   /**< Port for Temperature Sensor   */

/**
 * Include files
 */ 
#include <util/delay.h>
#include <avr/io.h>


/**
 * Function Definitions
 */

/**
 * @brief Change the state of the LED Pin according to the value of state
 * 
 * @param state Pin level to which the LED Pin should be set
 */
void change_led_state(uint8_t state);

/**
 * @brief Function to generate delay in micro seconds
 * 
 * @param[in] delay_time Delay in Micro seconds
 * 
 */
void delay_ms(uint32_t delay_time);

/**
 * @brief Initialize all the Peripherals and pin configurations
 * 
 */
void peripheral_init(void);

/**
 * @brief Activity 1 to Turn ON LED if switches for Button sensor and Heator sensor are pressed 
 * 
 */
int activity1(void);

#endif /* __ACTIVITY_1_H__ */