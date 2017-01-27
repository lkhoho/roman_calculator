/*
    FILE: int_to_roman.c
    AUTHOR: Ke Liu
*/

#include <stdlib.h>
#include <string.h>
#include "../inc/roman_group.h"
#include "../inc/int_to_roman.h"

static const int MAX_LENGTH = 64;

char *int_to_roman(int number) {
    char *result = (char *) calloc(MAX_LENGTH, sizeof(char));

    if (number <= 0) {
        return strcat(result, "zero or negative error");
    }

    int i;
    int reminder = number;

    while (reminder > 0) {
        for (i = ROMAN_TABLE_SIZE - 1; i >= 0; i--) {
            if (reminder / ROMAN_TABLE[i].value > 0) {
                strcat(result, ROMAN_TABLE[i].chars);
                reminder -= ROMAN_TABLE[i].value;
                break;
            }
        }
    }

    return result;
}
