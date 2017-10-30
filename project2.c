#include"uart.h"
#include<stdlib.h>
#include "cirbuf.h"
#include "project2.h"
extern CB_t *REC;
extern CB_t *SEND;
 CB_status p;
// uint8_t data;
 int pp=0;
 extern uint8_t alpha;
 extern uint8_t num;
 extern uint8_t punc;
 extern uint8_t misc;
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

/*void count_stats(uint8_t c,uint8_t alpha,uint8_t num,uint8_t punc,uint8_t misc)
{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
			alpha++;
		else if(c==33||c==34||c==39||c==44||c==46||c==58||c==59||c==63||c==96)
			punc++;
		else if(c>=48&&c<=57)
				num++;
		else
				misc++;



}*/
void print(uint8_t byte){

	uart_send_byte(byte);


}

uint8_t my_itoa (int32_t data, uint8_t * ptr, uint32_t base)
{

  uint8_t rem;//stores remainder
  //char c;
  int i;
  int32_t temp;			//a temporary variable
  temp = data;

  uint8_t length;
  length = 0;

  if (data < 0)			//makes data positive.sign can be added later on
    data = -(data);


  /*The if statements below take out each digit from the number
     and takes them into pointer/array */

  if (base == 2)
    {
      while (data != 0)
	{
	  rem = data % 2;
	  *(ptr) = rem + 48;
	  (ptr++);
	  length++;
	  data = data / 2;
	}
    }

  if (base == 8)
    {
      while (data != 0)
	{
	  rem = data % 8;
	  *(ptr) = rem + 48;
	  (ptr++);
	  length++;
	  data = data / 8;
	}
    }

  if (base == 10)
    {
      while (data != 0)
	{
	  rem = data % 10;
	  *(ptr) = rem + 48;
	  (ptr++);
	  length++;
	  data = data / 10;
	}
    }

  if (base == 16)
    {
      while (data != 0)
	{
	  rem = data % 16;
	  if (rem == 10)
	    *ptr = 'A';
	  else if (rem == 11)
	    *ptr = 'B';
	  else if (rem == 12)
	    *ptr = 'C';
	  else if (rem == 13)
	    *ptr = 'D';
	  else if (rem == 14)
	    *ptr = 'E';
	  else if (rem == 15)
	    *ptr = 'F';
	  else
	    *(ptr) = (rem + 48);
	  (ptr++);
	  length++;
	  data = data / 16;
	}
    }
  if (temp < 0)
    {
      *ptr = '-';
      ptr++;
      length++;
    }
  //*ptr='\0';
 ;

 int l;
	if(length%2==0){
		l=length/2;
	}
	else
		l=(length-1)/2;
	ptr=ptr-length;
	for(i=0;i<l;i++)
	{
		temp=*(ptr+i);
		*(ptr+i)=*(ptr+length-i-1);
		*(ptr+length-i-1)=temp;
	}
 //ptr=ptr-length;
  return length;
}



















