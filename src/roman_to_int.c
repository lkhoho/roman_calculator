/*
    FILE: roman_to_int.c
    AUTHOR: Ke Liu
*/

#include <string.h>
#include "../inc/roman_group.h"
#include "../inc/int_to_roman.h"
#include "../inc/roman_to_int.h"

static const int ERROR = -1;

int roman_to_int(const char *numeral) {
    if (!numeral) {
        return ERROR;
    }

    int i;
    int result = 0;
    const char *p = numeral; /* a pointer moving to the end of numeral */
    char *converted; /* used for verifying result */
    int isCharIdentified = 0; /* flag of current p is identified */
    while (*p) {
        isCharIdentified = 0;
        for (i = ROMAN_TABLE_SIZE - 1; i >= 0; i--) {
            if (strncmp(p, ROMAN_TABLE[i].chars, ROMAN_TABLE[i].length) == 0) {
                result += ROMAN_TABLE[i].value;
                p += ROMAN_TABLE[i].length;
                isCharIdentified = 1;
            }
        }

        if (isCharIdentified == 0) {
            return ERROR;
        }
    }

    /* verify result by convert result back to numerals */
    converted = int_to_roman(result);
    return (strcmp(converted, numeral) == 0) ? result : ERROR;
}
