#include <stdio.h>
#include "test_state.h"
#include "test_language.h"


int main(int argc, char** argv) {
	printf("Testing bfc:\n");
	printf("----------------------------------\n");

	printf("Testing state module:\n");
	state_all();
	printf("\n");

	printf("Testing language module:\n");
	language_all();
	printf("\n");

	return 0;
}
