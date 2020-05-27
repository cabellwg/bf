CCFLAGS = -Werror -Wall

ifeq ($(CC), clang)
	# Clang-specific logic
else
	# Otherwise, default to GCC
	CC = gcc
endif

build:
	-mkdir build
	$(CC) -o build/bfc -std=c11 src/*.c $(CCFLAGS)

test:
	$(CC) -o build/bfc_tests -std=c11 -ggdb3 tests/*.c $(CCFLAGS)
	./build/bfc_tests

.PHONY: test
