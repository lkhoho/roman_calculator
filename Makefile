CC = gcc
LD = gcc
LIB_PATH = /opt/local/lib/
CFLAGS = -Wall -std=c99 -O3
LDFLAGS = -lm
OBJS = roman_group.o int_to_roman.o roman_to_int.o roman_calculator.o
TEST_OBJS = test_roman_to_int.o test_int_to_roman.o test_roman_calculator.o
EXEC = roman_calculator
TEST_EXEC = run_tests

all: build_calculator build_tests

build_calculator: ${OBJS}
	${CC} ${CFLAGS} -c src/main.c
	${LD} ${LDFLAGS} $^ main.o -o ${EXEC}

build_tests: ${OBJS} ${TEST_OBJS}
	${CC} ${CFLAGS} -c tests/run_tests.c
	${LD} ${LDFLAGS} -L${LIB_PATH} -lcheck $^ run_tests.o -o ${TEST_EXEC}

${OBJS}: src/roman_group.c src/int_to_roman.c src/roman_to_int.c src/roman_calculator.c
	${CC} ${CFLAGS} -c $^

${TEST_OBJS}: tests/test_roman_to_int.c tests/test_int_to_roman.c tests/test_roman_calculator.c
	${CC} ${CFLAGS} -c $^

clean:
	rm *.o ${EXEC} ${TEST_EXEC}
