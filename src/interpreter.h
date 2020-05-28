#ifndef interpreter_h
#define interpreter_h

#include <stdio.h>


#define TAPE_LENGTH 30000


/*** Functions ***/

/**
 * Reads a Brainfuck file and prints the result to stdout.
 *
 * Parameters:
 *  - `FILE* input`: A pointer to the input file.
 *  - `char(* tape)[TAPE_LENGTH]`: The tape to work on
 *  - `FILE* in`: The file to read input from
 *  - `FILE* out`: The file to print out to
 *
 * Returns:
 *  - 0 if executed successfully
 *  - 1 if there was an unknown error
 *  - 2 if there were mismatched '[' and ']' delimiters
 *  - 3 if the program ran out of bounds
 */
int interpret(FILE* input, char(* tape)[TAPE_LENGTH], FILE* in, FILE* out);

#endif /* interpreter_h */
