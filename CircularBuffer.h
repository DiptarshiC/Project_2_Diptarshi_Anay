
/**

 * @file CircularBuffer.h 

 * @brief This file is to be used in project2

 *

 * @author Diptarshi Chakraborty

 * @date April 2, 2017

 *

 */

#ifndef __PROJECT1_H__

#define __PROJECT1_H__
#include<stdint.h>

#define	TEST_ERROR		1
#define TEST_NO_ERROR		0
#define BUFFER_SIZE		30
#define TOTAL_NO_OF_TESTS	10
/**

 * @brief function to test buffer allocation

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_allocate_free();


/**

 * @brief function to test invalid pointer

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_invalid_pointer();


/**

 * @brief function to test non initialized buffer

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_not_initialized();





/**

 * @brief function to test whether add and remove operations return the same length

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_add_remove();



/**

 * @brief function to test whether test returns true for buff full

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_buff_full();



/**

 * @brief function to test whether test returns true for buff empty

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_buff_empty();



/**

 * @brief function to test whether the Circular buffer can wrap add at the boundary

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_wrap_add();




/**

 * @brief function to test whether the Circular buffer can wrap  around when element is removed at boundary

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_wrap_remove();


/**

 * @brief function to test whether the Circular buffer can restrict overfill

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_overfill();




/**

 * @brief function to test whether the Circular buffer fails to remove when empty

 * This function calls some various simple tests that you can run to test 

 * your code for the project 2. The contents of these functions

 * have been provided. 

 * @return int

 */


int  test_empty();


#endif 

