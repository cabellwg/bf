#include <stdio.h>
#include "test_state.h"
#include "test_language.h"

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_COLOR_GREEN   "\x1b[32m"

int main(int argc, char** argv) {
	printf("Testing bfc:\n");
	printf("----------------------------------\n");

	printf("Testing state module:\n");
	state_all();
	printf("\n");

	printf("Testing language module:\n");
	language_all();
	printf("\n");

	printf("\n" ANSI_COLOR_GREEN "All tests passed!" ANSI_COLOR_RESET "\n\n");

	return 0;
}
