/*
    FILE: roman_group.h
    AUTHOR: Ke Liu
*/

#ifndef ROMAN_GROUP_H
#define ROMAN_GROUP_H

typedef struct _roman_group {
    int value;
    char chars[2];
    int length;
} RomanGroup;

extern const int ROMAN_TABLE_SIZE;
// extern RomanGroup *SMALLEST_GROUP;
// extern RomanGroup *LARGEST_GROUP;
extern RomanGroup ROMAN_TABLE[];

#endif