CCFLAGS = -Werror -Wall

ifeq ($(CC), clang)
	# Clang-specific logic
else
	# Otherwise, default to GCC
	CC = gcc
endif

build:
	-mkdir build
	$(CC) -o build/bf -std=c11 src/*.c $(CCFLAGS)

test:
	-mkdir build
	$(CC) -o build/bf_tests -std=c11 -ggdb3 tests/*.c $(CCFLAGS)
	./build/bf_tests

.PHONY: build test
