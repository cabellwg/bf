#ifndef language_h
#define language_h

#include "state.h"

/*** Functions ***/

/**
 * Reads a character and applies it to the state array.
 *
 * Parameters:
 *  - `State* state`: A pointer to the current tape state.
 *  - `char c`: The character to interpret.
 * 
 * Returns:
 *  - 0 if character changed the state successfully
 */
int read_char(State* state, char c);

#endif /* language_h */
