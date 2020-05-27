#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


#include "test_state.h"
#include "../src/state.c"


#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define NUM_TESTS 1


// Delegates

typedef void (*Test)(void);


// Environment Setup Function Declarations

static void set_up(void);
static void tear_down(void);


// Test Declarations

static void test_init_state(void);


// Globals

/*
 * Array of all test methods.
 */
static Test tests[NUM_TESTS] = {
        test_init_state
};


// Functions

void state_all() {
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
State* state;


// Environment Setup

/*
 * Runs before each test method.
 */
static void set_up() {
	state = init_state();
}


/*
 * Runs after each test method.
 */
static void tear_down() {
	destroy_state(&state);
}


// Test Definitions

/*
 * Tests the init_state method.
 */
static void test_init_state() {
	assert(state->position == 0);

	for (int i = 0; i < TAPE_LENGTH; i++) {
		assert(state->tape[i] == 0);
	}
}

