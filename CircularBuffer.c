


/**

 * @file CircularBuffer.c

 * @brief This file is to be used in project2

 *

 * @author Diptarshi Chakraborty

 * @date April 2, 2017

 *

 */







#include <stdio.h>
#include <stdint.h>
#include "cirbuf.h"
#include "CircularBuffer.h"

 	CB_t my_buff;									//Declaration of a circular buffer structure
	CB_status p;									//declaration present in cirbuf.c
	uint8_t e;
	CB_t *q=&my_buff;

/**

 * @brief function to test buffer allocation

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_allocate_free(){
		p=CB_init(&my_buff,8);
		if(p==3)
			return TEST_ERROR;
		else
			return TEST_NO_ERROR;
}

/**

 * @brief function to test invalid pointer

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_invalid_pointer(){
		       p=CB_init(&my_buff,8);
		if(p==3)
                        return TEST_ERROR;
                else
                        return TEST_NO_ERROR;
}



/**

 * @brief function to test non initialized buffer

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_not_initialized(){
		p=CB_init(&my_buff,8);
                if(p==3)
                        return TEST_ERROR;
                else
                        return TEST_NO_ERROR;




}
/**

 * @brief function to test whether add and remove operations return the same length

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_add_remove(){
		size_t count1,count2;				//keeping  a track of current no. of items
		p=CB_buffer_add_item(&my_buff,100);
		count1=q->count;
		p=CB_buffer_add_item(&my_buff,200);
		p=CB_buffer_add_item(&my_buff,240);
		p=CB_buffer_remove_item(&my_buff,&e);
		p=CB_buffer_remove_item(&my_buff,&e);
		count2=q->count;
		if(count1==count2)
			return TEST_NO_ERROR;
		else
			return TEST_ERROR;
}

/**

 * @brief function to test whether test returns true for buff full

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_buff_full(){

	       p=CB_buffer_add_item(&my_buff,200);
	       p=CB_buffer_add_item(&my_buff,200);
	       p=CB_buffer_add_item(&my_buff,200);
               p=CB_buffer_add_item(&my_buff,200);
               p=CB_buffer_add_item(&my_buff,200);
               p=CB_buffer_add_item(&my_buff,200);
               p=CB_buffer_add_item(&my_buff,200);
               p=CB_buffer_add_item(&my_buff,200);
	       p=CB_buffer_add_item(&my_buff,200);

               size_t count1=q->count;
	//	p=CB_is_full(&my_buff);
		if(p==buff_full)
			return TEST_NO_ERROR;
		else
			return TEST_ERROR;
		}

/**

 * @brief function to test whether test returns true for buff empty

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_buff_empty(){
	                p=CB_buffer_remove_item(&my_buff,&e);
			p=CB_buffer_remove_item(&my_buff,&e);
		        p=CB_buffer_remove_item(&my_buff,&e);
			p=CB_buffer_remove_item(&my_buff,&e);
			p=CB_buffer_remove_item(&my_buff,&e);
                        p=CB_buffer_remove_item(&my_buff,&e);
                        p=CB_buffer_remove_item(&my_buff,&e);
                        p=CB_buffer_remove_item(&my_buff,&e);
                        p=CB_buffer_remove_item(&my_buff,&e);

			p=CB_is_empty(&my_buff);
			if(p==1)
				return TEST_NO_ERROR;
			else
				return TEST_ERROR;


}
/**

 * @brief function to test whether the Circular buffer can wrap add at the boundary

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_wrap_add(){
		p=CB_init(&my_buff,4);
		p=CB_buffer_add_item(&my_buff,1);
		p=CB_buffer_remove_item(&my_buff,&e);
		p=CB_buffer_add_item(&my_buff,1);
		p=CB_buffer_add_item(&my_buff,2);
		p=CB_buffer_add_item(&my_buff,3);
		if(q->head==q->buff_point)
			return TEST_NO_ERROR;
		else
			return TEST_ERROR;
}
/**

 * @brief function to test whether the Circular buffer can wrap  around when element is removed at boundary

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_wrap_remove(){


		     p=CB_buffer_remove_item(&my_buff,&e);
		     p=CB_buffer_remove_item(&my_buff,&e);
		     p=CB_buffer_remove_item(&my_buff,&e);
		     if(q->tail==q->buff_point)
			return TEST_NO_ERROR;
		    else
			return TEST_ERROR;
}
/**

 * @brief function to test whether the Circular buffer can restrict overfill

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_overfill(){

	         p=CB_init(&my_buff,4);
	         p=CB_buffer_add_item(&my_buff,1);
	         p=CB_buffer_add_item(&my_buff,2);
      		 p=CB_buffer_add_item(&my_buff,3);
	         p=CB_buffer_add_item(&my_buff,4);
                 p=CB_buffer_add_item(&my_buff,5);
         	 if(p==0)
			return TEST_NO_ERROR;
		else
			return TEST_ERROR;
}
/**

 * @brief function to test whether the Circular buffer fails to remove when empty

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_empty(){


	  	     p=CB_buffer_remove_item(&my_buff,&e);
                     p=CB_buffer_remove_item(&my_buff,&e);
                     p=CB_buffer_remove_item(&my_buff,&e);
  		     p=CB_buffer_remove_item(&my_buff,&e);
                     p=CB_buffer_remove_item(&my_buff,&e);
		if(p==1)
                        return TEST_NO_ERROR;
                else
                        return TEST_ERROR;





}

/*

void main(){

		printf("\nThe result of n tests is as follows:\n");

		if(test_allocate_free()==TEST_NO_ERROR)
			printf("\nSTATUS:SUCCESSFUL\n");
		else
			printf("\nSTATUS:FAILED\n");

	        if(test_invalid_pointer()==TEST_NO_ERROR)
                        printf("\nSTATUS:SUCCESSFUL\n");
                else
                        printf("\nSTATUS:FAILED\n");

		if(test_not_initialized()==TEST_NO_ERROR)
                        printf("\nSTATUS:SUCCESSFUL\n");
                else
                        printf("\nSTATUS:FAILED\n");
		 if(test_add_remove()==TEST_NO_ERROR)
                        printf("\nSTATUS:SUCCESSFUL\n");
                else
                        printf("\nSTATUS:FAILED\n");

	        if(test_buff_full()==TEST_NO_ERROR)
                        printf("\nSTATUS:SUCCESSFUL\n");
                else
                        printf("\nSTATUS:FAILED\n");

		if(test_buff_empty()==TEST_NO_ERROR)
			printf("\nSTATUS:SUCCESSFUL\n");

		else
			printf("\nSTATUS:FAILED\n");

		if(test_wrap_add()==TEST_NO_ERROR)
			printf("\nSTATUS:SUCCESSFUL\n");

		else
			printf("\nSTATUS:FAILED\n");

	        if(test_wrap_remove()==TEST_NO_ERROR)
                        printf("\nSTATUS:SUCCESSFUL\n");

                else
                        printf("\nSTATUS:FAILED\n");

		if(test_overfill()==TEST_NO_ERROR)
                        printf("\nSTATUS:SUCCESSFUL\n");

                else
                        printf("\nSTATUS:FAILED\n");

	        if(test_empty()==TEST_NO_ERROR)
                        printf("\nSTATUS:SUCCESSFUL\n");

                else
                        printf("\nSTATUS:FAILED\n");




}
*/
