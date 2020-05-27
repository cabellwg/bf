#ifndef state_h
#define state_h


#include <inttypes.h>


/*** Constants ***/

#define TAPE_LENGTH 30000


/*** Structs ***/

/**
 * Represents the state of a memory tape. Memory tapes are initialized with TAPE_LENGTH positions, each set to 0.
 */
typedef struct State {
	char tape[TAPE_LENGTH];
	char* position;
} State;


/*** Functions ***/

/**
 * Builds a new memory tape state.
 *
 * Returns:
 * A pointer to a State struct with each entry of the tape initialized to 0 and the position initialized to 0.
 */
State* init_state(void);


/**
 * Destroys a memory tape state and the memory tape.
 *
 * Parameters:
 *  - `State** state`: A pointer to a pointer to the State struct to destroy. 
 */
void destroy_state(State** state);

#endif /* state_h */
