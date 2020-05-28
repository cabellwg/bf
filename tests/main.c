#include <stdio.h>
#include "test_interpreter.h"

#define ANSI_COLOR_RESET "\x1b[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

int main(int argc, char** argv) {
	printf("Testing bf:\n");
	printf("----------------------------------\n");

	printf("Testing interpreter module:\n");
	interpreter_all();
	printf("\n");

	printf("\n" ANSI_COLOR_GREEN "All tests passed!" ANSI_COLOR_RESET "\n\n");

	return 0;
}
