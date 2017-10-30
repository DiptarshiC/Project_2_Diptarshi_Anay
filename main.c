#include"uart.h"
#include<stdlib.h>
extern CB_t *REC;
extern CB_t *SEND;
 CB_status p;
// uint8_t data;
int main(void)

{
	REC=malloc(sizeof(CB_t));
	REC->buff_point=malloc(sizeof(uint8_t)*100);
	SEND=malloc(sizeof(CB_t));
	SEND->buff_point=malloc(sizeof(uint8_t)*100);
	p=CB_init(REC,100);
	p=CB_init(SEND,100);
	//p=CB_buffer_add_item(SEND,50);
	uart_configure();



while(1)
	{

	}
}


