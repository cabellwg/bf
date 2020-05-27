#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


#include "test_language.h"
#include "../src/language.c"

#define NUM_TESTS 0


// Delegates

typedef void (*Test)(void);


// Environment Setup Function Declarations

static void set_up(void);
static void tear_down(void);


// Test Declarations



// Globals

/*
 * Array of all test methods.
 */
static Test tests[NUM_TESTS] = {
};


// Functions

void language_all() {
    for (int i = 0; i < NUM_TESTS; i++) {
        set_up();
        printf("Running test %d ... ", i + 1);
        tests[i]();
        printf("passed.\n");  // Tests should halt execution of test suite on failure
        tear_down();
    }
}


/********************************************************
 *****************       Tests          *****************
 ********************************************************/


// Test Globals



// Environment Setup

/*
 * Runs before each test method.
 */
static void set_up() {
}


/*
 * Runs after each test method.
 */
static void tear_down() {
}


// Test Definitions

