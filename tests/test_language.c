#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


#include "test_language.h"
#include "../src/language.c"


#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"
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
        printf(ANSI_COLOR_GREEN "passed" ANSI_COLOR_RESET ".\n");
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

