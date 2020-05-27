#include <stdbool.h>
#include "interpreter.h"
#include "state.h"


/*** Static function declarations ***/

int read_action_char(State* state, char c);


/*** Public function definitions ***/

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
int interpret(FILE* input) {
	State* state = init_state();

	char c = '\0';
	while((c = fgetc(input)) != EOF) {
		if (c == '[' && current_value(state) == '\0') {
			int nest_level = 1;
			while (nest_level != 0) {
				c = fgetc(input);
				if (c == EOF) {
					return 2;
				} else if (c == '[') {
					nest_level++;
				} else if (c == ']') {
					nest_level--;
				}
			}

		} else if (c == ']' && current_value(state) == '\0') {
			int nest_level = 1;
			do {
				if (!fseek(input, -2, SEEK_CUR)) {
					return 2;
				}
				c = fgetc(input);

				if (c == EOF) {
					return 1;
				} else if (c == ']') {
					nest_level++;
				} else if (c == '[') {
					nest_level--;
				}
			} while (nest_level != 0);
		} else {
			if (!read_action_char(state, c)) {
				return 1;
			}
		}
	}

	destroy_state(&state);

	return 0;
}


/*** Private function definitions ***/

/**
 * Reads an action character and applies it to the state array.
 *
 * Parameters:
 *  - `State* state`: A pointer to the current tape state.
 *  - `char c`: The character to interpret.
 * 
 * Returns:
 *  - 0 if character changed the state successfully
 */
int read_action_char(State* state, char c) {
	return -1;
}
