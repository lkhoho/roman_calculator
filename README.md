# Roman Calculator

## Introduction
A simple calculator using Roman numerals. Addition and subtraction are supported.

## Project Structure
There are 4 modules for this calculator.
- int_to_roman: converts integer to Roman numerals.
- roman_to_int: converts Roman numerals to integers.
- roman_group: defines Roman numeral structure.
- main: defines the calculator operations (addition and subtraction).

## File Description
- directory inc: contains calculator header files.
- directory src: contains calculator source files.
- directory tests: contains unit tests (including header and source files used for unit test).
- file Makefile: Makefile to build the project.

## Build
GNU Makefile is used to build the project. Targets are:
- all: build calculator executable (roman_calculator) and unit test executable (run_tests).
- build_calculator: build calculator executable only.
- build_tests: build unit test executable only.
- clean: delete all executables and object files.

## Usage
roman_calculator *operand1 operator operand2*

Example: command **roman_calculator III + V** will return **III + V = VIII** as result.
