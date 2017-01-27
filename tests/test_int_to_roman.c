/*
    FILE: test_int_to_roman.c
    AUTHOR: Ke Liu
*/

#include <stdio.h>
#include <stdlib.h>
#include "../inc/int_to_roman.h"
#include "test_int_to_roman.h"

static void check_result(int input, const char *expected) {
    char *actual = int_to_roman(input);
    ck_assert_msg(strcmp(actual, expected) == 0,
        "convert %d: expected %s, but got %s\n", input, expected, actual);
    free(actual);
}

START_TEST(test_single_numerals)
{
    check_result(1, "I");
    check_result(5, "V");
    check_result(10, "X");
    check_result(50, "L");
    check_result(100, "C");
    check_result(500, "D");
    check_result(1000, "M");
}
END_TEST

START_TEST(test_combined_numerals)
{
    check_result(2, "II");
    check_result(3, "III");
    check_result(6, "VI");
    check_result(8, "VIII");
    check_result(23, "XXIII");
    check_result(123, "CXXIII");
    check_result(657, "DCLVII");
    check_result(3811, "MMMDCCCXI");
}
END_TEST

START_TEST(test_subtractive_numerals)
{
    check_result(4, "IV");
    check_result(9, "IX");
    check_result(95, "XCV");
    check_result(400, "CD");
    check_result(444, "CDXLIV");
    check_result(450, "CDL");
    check_result(900, "CM");
    check_result(950, "CML");
    check_result(3941, "MMMCMXLI");
}
END_TEST

START_TEST(test_zero_or_negative)
{
    check_result(0, "zero or negative error");
    check_result(-1, "zero or negative error");
    check_result(-123, "zero or negative error");
    check_result(-573282344, "zero or negative error");
}
END_TEST

TCase *int_to_roman_tests(void) {
    TCase *test_case = tcase_create("int_to_roman");
    tcase_add_test(test_case, test_single_numerals);
    tcase_add_test(test_case, test_combined_numerals);
    tcase_add_test(test_case, test_subtractive_numerals);
    tcase_add_test(test_case, test_zero_or_negative);
    return test_case;
}
