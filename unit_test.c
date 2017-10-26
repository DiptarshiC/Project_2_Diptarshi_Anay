
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "cirbuf.h"
#include "CircularBuffer.h"


void test_allocate_free_test(void **state){

	assert_int_equal(test_allocate_free(), 0);
}

void test_invalid_pointer_test(void **state){

        assert_int_equal(test_invalid_pointer(), 0);
}

void test_not_initialized_test(void **state){

        assert_int_equal(test_not_initialized(), 0);
}

void test_add_remove_test(void **state){

        assert_int_equal(test_add_remove(), 0);
}

void test_buff_full_test(void **state){

        assert_int_equal(test_buff_full(), 0);
}

void test_buff_empty_test(void **state){

        assert_int_equal(test_buff_empty(), 0);
}

void test_wrap_add_test(void **state){

        assert_int_equal(test_wrap_add(), 0);
}

void test_wrap_remove_test(void **state){

        assert_int_equal(test_wrap_remove(), 0);
}

void test_overfill_test(void **state){

        assert_int_equal(test_overfill(), 0);
}

void test_empty_test(void **state){

        assert_int_equal(test_empty(), 0);
}


int main(int argc, char **argv)
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_allocate_free_test),
    cmocka_unit_test(test_invalid_pointer_test),
   cmocka_unit_test(test_not_initialized_test),
   cmocka_unit_test(test_add_remove_test),
	cmocka_unit_test(test_buff_full_test),
	cmocka_unit_test(test_buff_empty_test),
	cmocka_unit_test(test_wrap_add_test),
	cmocka_unit_test(test_wrap_remove_test),
	cmocka_unit_test(test_overfill_test),
	cmocka_unit_test(test_empty_test),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
