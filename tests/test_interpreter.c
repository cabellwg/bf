#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


#include "test_interpreter.h"
#include "../src/interpreter.c"


#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define NUM_TESTS 16


// Delegates

typedef void (*Test)(void);


// Environment Setup Function Declarations

static void set_up(void);
static void tear_down(void);


// Test Declarations

static void test_add_one(void);
static void test_subtract_one(void);
static void test_shift_right(void);
static void test_shift_right_off_tape(void);
static void test_shift_left(void);
static void test_shift_left_off_tape(void);
static void test_forward_bracket(void);
static void test_forward_bracket_nested(void);
static void test_forward_bracket_nonzero(void);
static void test_forward_bracket_unmatched(void);
static void test_reverse_bracket(void);
static void test_reverse_bracket_nested(void);
static void test_reverse_bracket_zero(void);
static void test_reverse_bracket_unmatched(void);
static void test_read(void);
static void test_write(void);


// Globals

/*
 * Array of all test methods.
 */
static Test tests[NUM_TESTS] = {
	*test_add_one,
	*test_subtract_one,
	*test_shift_right,
	*test_shift_right_off_tape,
	*test_shift_left,
	*test_shift_left_off_tape,
	*test_forward_bracket,
	*test_forward_bracket_nested,
	*test_forward_bracket_nonzero,
	*test_forward_bracket_unmatched,
	*test_reverse_bracket,
	*test_reverse_bracket_nested,
	*test_reverse_bracket_zero,
	*test_reverse_bracket_unmatched,
	*test_read,
	*test_write
};


// Functions

void interpreter_all() {
    for (int i = 0; i < NUM_TESTS; i++) {
        set_up();
        printf("Running test %d ... ", i + 1);
        tests[i]();
        printf(ANSI_COLOR_GREEN "passed" ANSI_COLOR_RESET ".\n");
        tear_down();
    }
}


/********************************************************
 *****************       Tests          *****************
 ********************************************************/


// Test Globals

FILE* input;
char tape[TAPE_LENGTH] = {0};


// Environment Setup

/*
 * Runs before each test method.
 */
static void set_up() {
	input = fopen("test_input.bf", "w+");
	fprintf(input, "THIS IS A TEMPORARY FILE GENERATED FOR TESTING PURPOSES\n");
}


/*
 * Runs after each test method.
 */
static void tear_down() {
	memset(tape, 0, TAPE_LENGTH * sizeof(char));
	fclose(input);
	remove("test_input.bf");
}


// Test Definitions

/**
 * Tests the add one command.
 */
static void test_add_one() {
	fprintf(input, "++++");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin, stdout);

	assert((int)tape[0] == 4);
}


/**
 * Tests the subtract one command.
 */
static void test_subtract_one() {
	fprintf(input, "++++--");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin,  stdout);

	assert((int)tape[0] == 2);
}


/**
 * Tests the shift right command.
 */
static void test_shift_right() {
	fprintf(input, ">>>+");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin,  stdout);

	assert((int)tape[3] == 1);
}


/**
 * Tests the shift right command with out of bounds shifting.
 */
static void test_shift_right_off_tape() {
	for (int i = 0; i < (TAPE_LENGTH / 10) + 1; i++) {
		fprintf(input, ">>>>>>>>>>");
	}
	fseek(input, 0, SEEK_SET);

	int err = interpret(input, &tape, stdin,  stdout);

	assert(err == 3);
}

/**
 * Tests the shift left command.
 */
static void test_shift_left() {
	fprintf(input, ">>><<+");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin,  stdout);

	assert((int)tape[1] == 1);
}


/**
 * Tests the shift left command with out of bounds shifting.
 */
static void test_shift_left_off_tape() {
	fprintf(input, "<");
	fseek(input, 0, SEEK_SET);

	int err = interpret(input, &tape, stdin,  stdout);
	assert(err == 3);
}


/**
 * Tests []
 */
static void test_forward_bracket() {
	fprintf(input, "[++++]+");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin,  stdout);

	assert((int)tape[0] == 1);
}


/**
 * Tests nested []
 */
static void test_forward_bracket_nested() {
	fprintf(input, "[++[++++[+]]++]+");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin,  stdout);

	assert((int)tape[0] == 1);
}


/**
 * Tests [] with a nonzero tape value
 */
static void test_forward_bracket_nonzero() {
	fprintf(input, "+[++");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin,  stdout);

	assert((int)tape[0] == 3);
}

/**
 * Tests unmatched []
 */
static void test_forward_bracket_unmatched() {
	fprintf(input, "[+++++");
	fseek(input, 0, SEEK_SET);

	int err = interpret(input, &tape, stdin,  stdout);

	assert(err == 2);
}

/**
 * Tests ][
 */
static void test_reverse_bracket() {
	fprintf(input, "+>++[<+>-]");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin,  stdout);

	assert((int)tape[0] == 3);
}


/**
 * Tests nested ][
 */
static void test_reverse_bracket_nested() {
	fprintf(input, "+>++>+++[<+[<+>-]>-]");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin,  stdout);

	assert((int)tape[0] == 6);
}


/**
 * Tests ][ with zero tape value
 */
static void test_reverse_bracket_zero() {
	fprintf(input, "++>]+");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin,  stdout);

	assert((int)tape[1] == 1);
}


/**
 * Tests unmatched ][
 */
static void test_reverse_bracket_unmatched() {
	fprintf(input, "+]+");
	fseek(input, 0, SEEK_SET);

	int err = interpret(input, &tape, stdin,  stdout);

	assert(err == 2);
}


/**
 * Tests read command
 */
static void test_read() {
	FILE* test_in = fopen("test_in.txt", "w+");
	fprintf(test_in, "a");
	fseek(test_in, 0, SEEK_SET);
	fprintf(input, ",");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, test_in, stdout);

	assert(tape[0] == 'a');

	fclose(test_in);
	remove("test_in.txt");
}


/**
 * Tests write command
 */
static void test_write() {
	FILE* test_out = fopen("test_out.txt", "w+");

	fprintf(input, ">+++[<+++++++++++>-]<.");
	fseek(input, 0, SEEK_SET);

	interpret(input, &tape, stdin, test_out);

	assert(tape[0] == '!');

	fseek(test_out, 0, SEEK_SET);
	char output = fgetc(test_out);
	assert(output == '!');

	fclose(test_out);
	remove("test_out.txt");
}
