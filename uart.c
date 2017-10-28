#include"MKL25Z4.h"
#include"uart.h"
#include"CircularBuffer.h"
#include"cirbuf.h"

#define BDH_VAL			0
#define BDL_VAL			23

int8_t index = 0,rec;
CB_t *tx,*rx;

void UART_configure(void)
{

	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
    SIM_SOPT2 |= SIM_SOPT2_UART0SRC(1);  // set up clk and select clk source

    PORTA_PCR1 = PORT_PCR_MUX(2);
    PORTA_PCR2 = PORT_PCR_MUX(2);        // set alt for portA as UART0

    UART0_C2=0x00;
    UART0_C1=0x00;                       // clear the registers before using

    SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;   // set clk for port A

    UART0_BDH |= (BDH_VAL << UART0_BDH_SBR_SHIFT);  //set baud rate
    UART0_BDL |= (BDL_VAL << UART0_BDL_SBR_SHIFT);
    UART0_C4 |= (OSR_VAL << UART0_C4_OSR_SHIFT);

    UART0_BDH |= 0;                     //set stop bit

    UART0_C2 |= UART0_C2_TE_MASK | UART0_C2_RE_MASK | UART0_C2_RIE_MASK; //set transmission and reception

    #ifdef Global_Interrupt
    __enable_irq();                        //enable interrupts
    NVIC->ISER[0] |= UART0_INT_ENABLE_MASK;//enable uart0 interrupt in nvic
    #endif
}

void UART_send(uint8_t *data_send)
{   while(!(UART0_S1 & UART0_S1_TDRE_MASK))
    {
	     UART0_D = *data_send;
    }
}

void UART_send_n(uint8_t *data_send, uint32_t length)
{
	uint8_t i,* ptr;
	ptr = &i;
	for(i=0;i<length;i++)
	{
		i = *data_send;
		UART_send(ptr);
		data_send++;
	}
}

void UART_receive(uint8_t *data_receive)
{
	while (!(UART0->S1 & UART0_S1_RDRF_MASK))
	{
	*data_receive = UART0->D;

	}
}

void UART_receive_n(uint8_t *data_receive, uint32_t length)
{
	while (length--)
	      {
	      UART_receive(*data_receive++);
	      }

}

void UART0_IRQHandler()
{
		__disable_irq();
		if (UART0_S1 & UART_S1_RDRF_MASK){
	        rec = UART0_D;
	        CB_buffer_add_item(rx,rec);
		}
	   if(index == 4)
	   {
		   UART0_C2 &= ~UART0_C2_TIE_MASK;
	   }
	   else	if (UART0_S1 & UART_S1_TDRE_MASK)
	   {
            CB_buffer_remove_item(&tx,rec);
			UART_send(rec);
			index++;

		}

		__enable_irq();
}
