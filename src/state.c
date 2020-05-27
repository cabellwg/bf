#include <stdlib.h>
#include "state.h"


/**
 * Creates a new State object.
 */
State* init_state() {
	State* state = calloc(1, sizeof(State));
	return state;
}


/**
 * Destroys a State object.
 */
void destroy_state(State** state) {
	free(*state);
	*state = (State*)NULL;
}

