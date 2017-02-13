/*
    FILE: roman_calculator.c
    AUTHOR: Ke Liu
*/

#include <stdlib.h>
#include <string.h>
#include "../inc/roman_to_int.h"
#include "../inc/int_to_roman.h"
#include "../inc/roman_calculator.h"

static const int ERROR = -1;
const char *OPERAND_ERROR = "operand(s) error";
const char *ZERO_ERROR = "zero";

// static char *copy_str(const char *src, char **dest) {
//     *dest = (char *) malloc(sizeof(char) * (strlen(src) + 1));
//     strcpy(*dest, src);
//     return *dest;
// }

char *add(const char *operand1, const char *operand2) {
    int op1 = roman_to_int(operand1);
    int op2 = roman_to_int(operand2);
    int sum = 0;

    if (op1 == ERROR || op2 == ERROR) {
        // return copy_str(OPERAND_ERROR);
        return (char *) OPERAND_ERROR;
    }

    sum = op1 + op2;
    return int_to_roman(sum);
}

char *substract(const char *operand1, const char *operand2) {
    int op1 = roman_to_int(operand1);
    int op2 = roman_to_int(operand2);
    int diff = 0;

    if (op1 == ERROR || op2 == ERROR) {
        // return copy_str(OPERAND_ERROR);
        return (char *) OPERAND_ERROR;
    }

    diff = op1 - op2;
    if (diff == 0) {
      // return copy_str(ZERO_ERROR);
      return (char *) ZERO_ERROR;
    } else {
        return int_to_roman(diff);
    }
}
