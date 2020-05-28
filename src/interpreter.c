#include <stdbool.h>
#include "interpreter.h"


/*** Static function declarations ***/

int read_action_char(char** state,
		     const char* tape_start,
		     const char* tape_end,
		     char c,
		     FILE* in,
		     FILE* out);


/*** Public function definitions ***/

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
int interpret(FILE* input, char(* tape)[TAPE_LENGTH], FILE* in, FILE* out) {
	char* state = *tape;
	const char* TAPE_START = state;
	const char* TAPE_END = state + TAPE_LENGTH - 1;

	char c = '\0';
	while((c = fgetc(input)) != EOF) {
		if (c == '[' && !*state) {
			int nest_level = 1;
			while (nest_level > 0) {
				c = fgetc(input);
				if (c == EOF) { return 2; }
				else if (c == '[') { nest_level++; }
				else if (c == ']') { nest_level--; }
			}

		} else if (c == ']' && *state) {
			int nest_level = 1;
			while (nest_level > 0) {
				if (fseek(input, -2, SEEK_CUR)) { return 2; }
				c = fgetc(input);
				if (c == EOF) { return 1; }
				else if (c == ']') { nest_level++; }
				else if (c == '[') { nest_level--; }
			}
		} else {
			int err = read_action_char(&state, TAPE_START, TAPE_END, c, in, out);
			if (err) { return err; }
		}
	}

	return 0;
}


/*** Private function definitions ***/

/**
 * Reads an action character and applies it to the state array.
 *
 * Parameters:
 *  - `State* state`: A pointer to the current tape state.
 *  - `char c`: The character to interpret.
 *  - `FILE* in`: The file to read input from
 *  - `FILE* out`: The file to print out to
 * 
 * Returns:
 *  - 0 if character changed the state successfully
 *  - 3 if the program ran out of bounds
 */
int read_action_char(char** state,
		     const char* tape_start,
		     const char* tape_end,
		     char c,
		     FILE* in,
		     FILE* out) {
	if (c == '>') { if (*state < tape_end) { (*state)++; } else { return 3; } }
	else if (c == '<') { if (*state > tape_start) { (*state)--; } else { return 3; } }
	else if (c == '+') { (**state)++; }
	else if (c == '-') { (**state)--; }
	else if (c == '.') { fputc(**state, out); }
	else if (c == ',') { **state = fgetc(in); }
	return 0;
}
