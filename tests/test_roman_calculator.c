/*
    FILE: test_roman_calculator.c
    AUTHOR: Ke Liu
*/

#include <stdlib.h>
#include "../inc/roman_calculator.h"
#include "test_roman_calculator.h"

static void check_add_result(const char *op1, const char *op2, const char *expected) {
    char *actual = add(op1, op2);
    ck_assert_msg(strcmp(actual, expected) == 0,
        "Expected %s + %s = %s, but got %s\n", op1, op2, expected, actual);
    free(actual);
}

static void check_substract_result(const char *op1, const char *op2, const char *expected) {
    char *actual = substract(op1, op2);
    ck_assert_msg(strcmp(actual, expected) == 0,
        "Expected %s - %s = %s, but got %s\n", op1, op2, expected, actual);
    free(actual);
}

START_TEST(test_add)
{
    check_add_result("I", "I", "II");
    check_add_result("II", "III", "V");
    check_add_result("D", "D", "M"); /* 500 + 500 = 1000 */
    check_add_result("CXLIX", "I", "CL"); /* 149 + 1 = 150 */
    check_add_result("XXXVI", "IV", "XL"); /* 36 + 4 = 40 */
    check_add_result("MMXII", "XXXVI", "MMXLVIII"); /* 2012 + 36 = 2048 */
    check_add_result("MCMXCVI", "V", "MMI"); /* 1996 + 5 = 2001 */
}
END_TEST

START_TEST(test_substract)
{
    check_substract_result("III", "II", "I");
    check_substract_result("VI", "I", "V");
    check_substract_result("X", "I", "IX");
    check_substract_result("D", "C", "CD"); /* 500 - 100 = 400 */
    check_substract_result("XXXVI", "XVIII", "XVIII"); /* 36 - 18 = 18 */
    check_substract_result("MCMXCVI", "M", "CMXCVI"); /* 1996 - 1000 = 996 */
    check_substract_result("MCMXCVI", "XXXVI", "MCMLX"); /* 1996 - 36 = 1960 */
    check_substract_result("MMXII", "MCMXCVI", "XVI"); /* 2012 - 1996 = 16 */
}
END_TEST

START_TEST(test_errors)
{
    check_add_result("", NULL, "operand(s) error");
    check_add_result("I", "NULL", "operand(s) error");
    check_add_result("A", "I", "operand(s) error");
    check_add_result("C", "Z", "operand(s) error");
    check_add_result("@", "$", "operand(s) error");
    check_substract_result("V", NULL, "operand(s) error");
    check_substract_result("NULL", "CM", "operand(s) error");
    check_substract_result("P", "I", "operand(s) error");
    check_substract_result("XXXVI", "U", "operand(s) error");
    check_substract_result("B", "&", "operand(s) error");
    check_substract_result("III", "III", "zero");
    check_substract_result("MMXII", "MMXII", "zero");
}
END_TEST

TCase *roman_calculator_tests(void) {
    TCase *test_case = tcase_create("roman_calculator");
    tcase_add_test(test_case, test_add);
    tcase_add_test(test_case, test_substract);
    tcase_add_test(test_case, test_errors);
    return test_case;
}
