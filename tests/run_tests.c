/*
    FILE: run_tests.c
    AUTHOR: Ke Liu
*/

#include <stdlib.h>
#include <check.h>
#include "test_roman_to_int.h"
#include "test_int_to_roman.h"
#include "test_roman_calculator.h"

int main(void) {
    Suite *suite = suite_create("roman calculator tests");
    suite_add_tcase(suite, roman_to_int_tests());
    suite_add_tcase(suite, int_to_roman_tests());
    suite_add_tcase(suite, roman_calculator_tests());

    SRunner *runner = srunner_create(suite);
    srunner_run_all(runner, CK_NORMAL);
    int failure_count = srunner_ntests_failed(runner);
    srunner_free(runner);

    return (failure_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
