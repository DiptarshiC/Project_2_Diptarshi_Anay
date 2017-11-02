#include <stdio.h>
#include <stdint.h>
#include "memory.h"
#include <cmocka.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>


#define TEST_NO_ERROR	1
#define TEST_ERROR		0

int test_InvalidPointer0(void **state)             //for memmove
{
  src = NULL;
  dst= NULL;
  length= 8;
  dst= my_memmove(src, dst,length);
  if( dst == NULL )                                //checked if it shows NULL as per the code
  {
  printf(" Null pointer handled.");
  }
  return TEST_NO_ERROR;
  assert_int_equal(1,1);
  else
  printf(" Null pointer not handled.");
  return TEST_ERROR;
  assert_int_equal(1,0);
}

int test_NoOverlap(void **state)
{
    int a[30];
    src= &a[4];
    dst= &a[14];
    length = 8;
    dst= my_memmove(src, dst,length);
    if ( src + length > dst)                               //checks if src and dst are overlapping 
    {
    printf(" Overlap not handled");
    }
    return TEST_ERROR;
    assert_int_equal(1,0);
    else 
    {
    printf(" Overlap handled");
    return TEST_NO_ERROR;
    assert_int_equal(1,1);
}

int test_SRCinDST(void **state)
{
    int a[30];
    src= &a[4];
    dst= &a[9];
    length = 8;
    dst= my_memmove(src, dst,length);
    if ( src + length > dst)                                           //checks if there's any src in dst
    {
    printf(" SRC in DST overlap");
    }
    return TEST_ERROR;
    assert_int_equal(1,0);
    else 
    {
    printf(" NO SRC in DST overlap");
    return TEST_NO_ERROR;
    assert_int_equal(1,1);
}

int test_DSTinSRC(void **state)
{
    int a[30];
    src= &a[8];
    dst= &a[4];
    length = 8;
    dst= my_memmove(src, dst,length);
    if ( dst + length > src)                                                  //checks if there's any src in dst
    {
    printf(" DST in SRC overlap");
    }
    return TEST_ERROR;
    assert_int_equal(1,0);
    else 
    {
    printf(" No DST in SRC overlap");
    return TEST_NO_ERROR;
    assert_int_equal(1,1);
}

int test_InvalidPointer1(void **state)              //for memset
{
    src = NULL;
    length= 8;
    value = 3;
    src= my_memset(src,length, value);
    if( src == NULL )                                                     //checks if null pointer is handled 
    printf(" Null pointer handled.");
    return TEST_NO_ERROR;
    assert_int_equal(1,1);
    else
    printf(" Null pointer not handled.");
    return TEST_ERROR;
    assert_int_equal(1,0);
}

int test_checkset_length(void **state)
{   
    src= malloc(50 * sizeof(int8_t));
    dst= malloc(50 * sizeof(int8_t));
    value= 0x40;
    length = 10;
    for(int i=0;i< length; i++)           //checks if the same value is at all locations by cokmparing it to hardcoded value
    {
      *dst = 0x40;
      dst++;
    }
    src = my_memset(src, length, value);
    for(int i=0;i< length; i++)
    {
    if(*src == *dst) 
    {
       src++;
       dst++;
    }
    else
    {
       return TEST_NO_ERROR;
       printf("Correct Set");
       assert_int_equal(1,1);
    }
    }
    return TEST_ERROR;
    printf("Incorrect Set");
    assert_int_equal(1,0);
}


int test_InvalidPointer2(void **state)              //for memzero
{
   src = NULL;
   length= 8;
   src= my_memzero(src,length);
   if( src == NULL )
   printf(" Null pointer handled.");                  //checks if NULL pointer is handled in the code.
   assert_int_equal(1,1);
   else
   printf(" Null pointer not handled.");
   assert_int_equal(1,1);  
}

int test_checkset_zero(void **state)
{   
    src= malloc(50 * sizeof(int8_t));
    dst= malloc(50 * sizeof(int8_t));
    length = 10;
    for(int i=0;i< length; i++)           //checks if 0 is at all locations by comparing it to hardcoded value
    {
      *dst = 0x00;
      dst++
    }
    src = my_memzero(src, length);
    for(int i=0;i< length; i++)
    {
    if(*src == *dst)
    {
       src++;
       dst++;
    }
    else
    {
       return TEST_NO_ERROR;
       printf("Correct Set");
       assert_int_equal(1,1);
    }
    }
    return TEST_ERROR;
    printf("Incorrect Set");
    assert_int_equal(1,0);
}

int test_InvalidPointer3(void **state)               //for reverse
{
  src = NULL;
  length= 8;
  src= my_reverse(src,length);
  if( src == NULL )
  printf(" Null pointer handled.");                 //checks if NULL pointer is handled in the code.
  assert_int_equal(1,1);
  else
  printf(" Null pointer not handled.");
  assert_int_equal(1,1); 
}

int test_Checkodd(void **state)
{ int a[5]= {1,2,3,4,5};
  src= &a[0];
  int b[5]= {5,4,3,2,1};
  dst= &b[0];
  src = malloc(10 * sizeof(int8_t));               
  length=5;
  src = my_reverse( src,length);                      //  check if it reverses for odd length
  for(int i=0;i< length; i++)
    {
    if(*src == *dst)
    {
       src++;
       dst++;
    }
    else
    {
       return TEST_NO_ERROR;
       printf("Correct Odd Reverse");
       assert_int_equal(1,1);
    }
    }
    return TEST_ERROR;
    printf("Incorrect Odd Reverse");
    assert_int_equal(1,0);
  
}

int test_Checkeven(void **state)
{
   int a[4]= {1,2,3,4};
  src= &a[0];
  int b[4]= {4,3,2,1};
  dst= &b[0];
  src = malloc(10 * sizeof(int8_t));
  length=4;
  src = my_reverse( src,length);                      //  check if it reverses for even length
  for(int i=0;i< length; i++)
    {
    if(*src == *dst)
    {
       src++;
       dst++;
    }
    else
    {
       return TEST_NO_ERROR;
       printf("Correct Even Reverse");
       assert_int_equal(1,1);
    }
    }
    return TEST_ERROR;
    printf("Incorrect Odd Reverse");
    assert_int_equal(1,0);
  
}

int test_Checkchar(void **state)
{
   
    int a[255]= {1,2,3,4,'A','B','C'};
  src= &a[0];
  int b[255];
  b[255]=1;
  b[254]=2;
  b[253]=3;
  b[252]=4;
  b[251]='A';
  b[250]='B';
  b[249]='C';
  dst= &b[0];
  src = malloc(10 * sizeof(int8_t));
  length=255;
  src = my_reverse( src,length);
  for(int i=0;i< length; i++)
    {
    if(*src == *dst)
    {
       src++;
       dst++;
    }
    else
    {
       return TEST_NO_ERROR;
       printf("Correct Char Reverse");                      //  check if it reverses for char
       assert_int_equal(1,1);
    }
    }
    return TEST_ERROR;
    printf("Incorrect Char Reverse");
    assert_int_equal(1,0);
}







int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
  cmocka_unit_test(test_InvalidPointer0),
  cmocka_unit_test(test_NoOverlap),
  cmocka_unit_test(test_SRCinDST),
  cmocka_unit_test(test_DSTinSRC),
  cmocka_unit_test(test_InvalidPointer1),
  cmocka_unit_test(test_checkset_length),
  cmocka_unit_test(test_InvalidPointer2),
  cmocka_unit_test(test_checkset_zero),
  cmocka_unit_test(test_InvalidPointer3),
  cmocka_unit_test(test_Checkodd),
  cmocka_unit_test(test_Checkeven),
  cmocka_unit_test(test_Checkchar),
  };


  return cmocka_run_group_tests(tests, NULL, NULL);
