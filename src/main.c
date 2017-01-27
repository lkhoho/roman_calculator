/*
    FILE: main.c
    AUTHOR: Ke Liu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/roman_calculator.h"

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: roman_calculator <op1> <operator> <op2>\n");
        return EXIT_FAILURE;
    }

    const char *op1 = argv[1];
    const char *operator = argv[2];
    const char *op2 = argv[3];

    if (strcmp(operator, "+") == 0) {
        fprintf(stdout, "%s + %s = %s\n", op1, op2, add(op1, op2));
    } else if (strcmp(operator, "-") == 0) {
        fprintf(stdout, "%s - %s = %s\n", op1, op2, substract(op1, op2));
    } else {
        fprintf(stderr, "Error: unknown operation\n");
    }

    return EXIT_SUCCESS;
}
