/*
    FILE: test_roman_to_int.c
    AUTHOR: Ke Liu
*/

#include "../inc/roman_to_int.h"
#include "test_roman_to_int.h"

START_TEST(test_single_numerals)
{
    ck_assert_int_eq(roman_to_int("I"), 1);
    ck_assert_int_eq(roman_to_int("V"), 5);
    ck_assert_int_eq(roman_to_int("X"), 10);
    ck_assert_int_eq(roman_to_int("L"), 50);
    ck_assert_int_eq(roman_to_int("C"), 100);
    ck_assert_int_eq(roman_to_int("D"), 500);
    ck_assert_int_eq(roman_to_int("M"), 1000);
}
END_TEST

START_TEST(test_additive_numerals)
{
    ck_assert_int_eq(roman_to_int("II"), 2);
    ck_assert_int_eq(roman_to_int("XXX"), 30);
    ck_assert_int_eq(roman_to_int("XXIII"), 23);
    ck_assert_int_eq(roman_to_int("XXXVI"), 36);
    ck_assert_int_eq(roman_to_int("CCCXII"), 312);
    ck_assert_int_eq(roman_to_int("CML"), 950);
    ck_assert_int_eq(roman_to_int("MD"), 1500);
    ck_assert_int_eq(roman_to_int("MDCLXVI"), 1666);
    ck_assert_int_eq(roman_to_int("MMXII"), 2012);
}
END_TEST

START_TEST(test_subtractive_numerals)
{
    ck_assert_int_eq(roman_to_int("IV"), 4);
    ck_assert_int_eq(roman_to_int("IX"), 9);
    ck_assert_int_eq(roman_to_int("XLV"), 45);
    ck_assert_int_eq(roman_to_int("XCV"), 95);
    ck_assert_int_eq(roman_to_int("XC"), 90);
    ck_assert_int_eq(roman_to_int("CD"), 400);
    ck_assert_int_eq(roman_to_int("CM"), 900);
    ck_assert_int_eq(roman_to_int("MCDXCIV"), 1494);
    ck_assert_int_eq(roman_to_int("MCMXCVI"), 1996);
}
END_TEST

START_TEST(test_unknown_characters)
{
    ck_assert_int_eq(roman_to_int("A"), -1);
    ck_assert_int_eq(roman_to_int("IXFI"), -1);
    ck_assert_int_eq(roman_to_int("#"), -1);
    ck_assert_int_eq(roman_to_int("@"), -1);
    ck_assert_int_eq(roman_to_int("VI9"), -1);
}
END_TEST

START_TEST(test_null_string)
{
    ck_assert_int_eq(roman_to_int(NULL), -1);
}
END_TEST

START_TEST(test_invalid_numerals)
{
    ck_assert_int_eq(roman_to_int("IIII"), -1);
    ck_assert_int_eq(roman_to_int("XXXXXX"), -1);
    ck_assert_int_eq(roman_to_int("CCCC"), -1);
    ck_assert_int_eq(roman_to_int("VV"), -1);
    ck_assert_int_eq(roman_to_int("LLL"), -1);
    ck_assert_int_eq(roman_to_int("DDDDDD"), -1);
    ck_assert_int_eq(roman_to_int("VIV"), -1);
    ck_assert_int_eq(roman_to_int("CMCM"), -1);
}
END_TEST

TCase *roman_to_int_tests(void) {
    TCase *test_case = tcase_create("roman_to_int");
    tcase_add_test(test_case, test_single_numerals);
    tcase_add_test(test_case, test_additive_numerals);
    tcase_add_test(test_case, test_subtractive_numerals);
    tcase_add_test(test_case, test_unknown_characters);
    tcase_add_test(test_case, test_null_string);
    tcase_add_test(test_case, test_invalid_numerals);
    return test_case;
}
