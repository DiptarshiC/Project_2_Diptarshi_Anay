/*
 * uart.h
 *
 *  Created on: 22-Oct-2017
 *      Author: Anay
 */

#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_

#define SIM_SOPT2_MCGFLLCLK_MASK 0x4000000u

#define UART0_INT_ENABLE_MASK 0x00001000u

#define Global_Interrupt

#define OSR_VAL 15


void UART_configure(void);
void UART_send(uint8_t *data);
void UART_send_n(uint8_t *data_send, uint32_t length);
void UART_receive(uint8_t *data);
void UART_receive_n(uint8_t *data_receive, uint32_t length);
void UART0_IRQHandler();

#endif /* INCLUDES_UART_H_ */
