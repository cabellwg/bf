#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "interpreter.h"

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		printf("bf: try 'bf --help' for more information\n");
		return 1;
	}

	if (argc > 1) {
		if (strncmp(argv[1], "--help", 6) == 0) {
			printf("Usage: bf <source_file.bf>\n");
		} else if (strncmp(argv[1], "-v", 2) == 0 ||
			   strncmp(argv[1], "--version", 9) == 0) {
			printf("bf by William Cabell: v1.0.0\n");
		} else {
			FILE* input_file = fopen(argv[1], "r");
			if (input_file == NULL) {
				printf("bf: unexpected error occurred\n");
				return 1;
			}
			
			char tape[TAPE_LENGTH] = {0};
			int err = interpret(input_file, &tape, stdin, stdout);
			if (err != 0) {
				printf("bf: encountered syntax error");
				return 2;
			}
	
			printf("\n");

			fclose(input_file);
		}
	}
	return 0;
}

