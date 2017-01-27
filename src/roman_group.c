/*
    FILE: roman_group.c
    AUTHOR: Ke Liu
*/

#include "../inc/roman_group.h"

RomanGroup ROMAN_TABLE[] = {
    {1, "I", 1},
    {4, "IV", 2},
    {5, "V", 1},
    {9, "IX", 2},
    {10, "X", 1},
    {40, "XL", 2},
    {50, "L", 1},
    {90, "XC", 2},
    {100, "C", 1},
    {400, "CD", 2},
    {500, "D", 1},
    {900, "CM", 2},
    {1000, "M", 1}
};

const int ROMAN_TABLE_SIZE = sizeof(ROMAN_TABLE) / sizeof(RomanGroup);
// RomanGroup *SMALLEST_GROUP = &ROMAN_TABLE[0];
// RomanGroup *LARGEST_GROUP = &ROMAN_TABLE[ROMAN_TABLE_SIZE - 1];