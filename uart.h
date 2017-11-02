/*

 * uart.h

 *

 *  Created on: 28th Oct , 2017

 *      Author: Diptarshi Chakraborty

 */
#include<stdint.h>
extern uint8_t rec1;
#include<stdint.h>
#ifndef INCLUDES_UART_H_

#define INCLUDES_UART_H_



#define SIM_SOPT2_MCGFLLCLK_MASK 0x4000000u



#define UART0_INT_ENABLE_MASK 0x00001000u



#define INTERRUPT



#define OSR_VAL 15



#define SBR_VAL 0x17

void uart_configure(void);

void uart_send(uint8_t data);

void uart_send_n(uint8_t *data, uint32_t length);

int8_t uart_recieve_byte (void);



#endif /* INCLUDES_UART_H_ */

