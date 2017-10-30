#include"MKL25Z4.h"
#include"uart.h"
#include "cirbuf.h"
#include<stdint.h>
#include<stdlib.h>
uint8_t rec1;
//CB_t send;
//CB_t receive;
CB_t *REC;
CB_t *SEND;
uint8_t data;
CB_status p;
void uart_configure(void){

#ifdef INTERRUPT

	__enable_irq();//enable global interrupts

	NVIC->ISER[0] |= UART0_INT_ENABLE_MASK;//enable uart0 interrupt in nvic

#endif

	SIM_SOPT2 |= SIM_SOPT2_MCGFLLCLK_MASK;//enable fll clock

	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;//enable clock gate

	UART0_C2 &= ~(UART0_C2_TE_MASK | UART0_C2_RE_MASK);//disable transmit and receive for config

	UART0_BDH &= 0x00;

	UART0_BDL |= SBR_VAL;

	UART0_C4 |= OSR_VAL;

	UART0_C2 |= (UART0_C2_TE_MASK | UART0_C2_RE_MASK );//enable transmit and receive

	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;//enable porta clock

	PORTA_PCR1 = PORT_PCR_MUX(2);//pinmux

	PORTA_PCR2 = PORT_PCR_MUX(2);//pinmux

	//UART0_C2=|=(UART0_C2_TE_MASK|UART0_C2_RE_MASK);

	UART0_C2 |= UART0_C2_RIE_MASK; //Enable receiver interrupt
}



void uart_send(int8_t data){

	UART0_D = data;

}



void uart_send_n(uint8_t *data, uint32_t length){

	uint8_t i;

	for(i=0;i<length;i++){

#ifndef INTERRUPT

	while(!(UART0_S1_REG(UART0_BASE_PTR) & UART0_S1_TDRE_MASK));

#endif

	UART0_D_REG(UART0_BASE_PTR) = *data;

	data++;

	}

}



int8_t uart_recieve_byte (void){



    return UART0_D_REG(UART0_BASE_PTR);

}

void UART0_IRQHandler(void)

{

	__disable_irq();


	if ((UART0_C2 & UART0_C2_RIE_MASK)==(UART0_C2_RIE_MASK)){

        rec1 = UART0_D;
        p=CB_buffer_add_item(REC,rec1);

     UART0_C2&=~UART0_C2_RIE_MASK;
     UART0_C2 |= UART0_C2_TIE_MASK;

	}
   else	if ((UART0_C2 & UART0_C2_TIE_MASK)==(UART0_C2_TIE_MASK))
   {
	   p= CB_buffer_remove_item(SEND,&rec1);
	   UART0_D = rec1;
	  // uart_send_byte(*SEND.tail);

	   UART0_C2 &= ~UART0_C2_TIE_MASK;
	   UART0_C2 |=UART0_C2_RIE_MASK;

    }


__enable_irq();

}



