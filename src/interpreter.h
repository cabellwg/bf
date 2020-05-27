#ifndef interpreter_h
#define interpreter_h

#include <stdio.h>

/*** Functions ***/

/**
 * Reads a Brainfuck file and prints the result to stdout.
 *
 * Parameters:
 *  - `FILE* input`: A pointer to the input file.
 *
 * Returns:
 *  - 0 if executed successfully
 *  - 1 if there was an unknown error
 *  - 2 if there were mismatched '[' and ']' delimiters
 */
int interpret(FILE* input);

#endif /* interpreter_h */
