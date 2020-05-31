#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "interpreter.h"

int main(int argc, char* argv[]) {
	if (argc <= 1) {
		printf("How stupid do you have to be to run a program without even looking "
		       "for the right invocation? Maybe try 'bf --help' first?\n");
		return 1;
	}

	if (strncmp(argv[1], "--help", 6) == 0) {
		printf("Welcome to bf, the friendly Brainfuck interpreter! :)\n");
		printf("Usage: bf <source_file.bf>\n");
		return 0;
	} else if (strncmp(argv[1], "-v", 2) == 0 ||
		   strncmp(argv[1], "--version", 9) == 0) {
		printf("Welcome to bf, the friendly Brainfuck interpreter! :)\n");
		printf("bf by William Cabell: v1.0.0\n");
		return 0;
	}
	FILE* input_file = fopen(argv[1], "r");
	if (input_file == NULL) {
		int err = errno;
		if (err == ENOMEM) {
			printf("You ran out of memory. You know what, this time "
			       "I'm going to be helpful. There's an easy way to "
			       "fix this one. Go on the Internet and search for "
			       "'download more RAM'. Do that, and you'll have "
			       "plenty of memory.\n");
		} else if (err == EACCES) {
			printf("Oh, you thought it would be funny if you tried "
			       "to give me a file that I couldn't read. 'Oh!',"
			       " you thought, 'let's show bf what it feels like!'\n");
		} else if (err == ELOOP) {
			printf("There was a problem with that symbolic link. Kind "
			       "of like every single relationship you've ever had.\n");
		} else if (err == ENFILE) {
			printf("You have too many files open, so, just like you should "
			       "do with all your dreams, go and close some of them.\n");
		} else if (err == ENAMETOOLONG) {
			printf("Specified file name is too long. Just like your "
			       "parents' funerals.\n");
		} else if (err == ENOENT) {
			printf("Hey! curl! git! Get over here and look at this! This idiot "
			       "can't even type correctly! They said, 'you should interpret"
			       " %s'! Hahahaha!\n", argv[1]);
		} else if (err == ENOTDIR) {
			printf("A directory in the specified path is as existent as "
			       "the meaning of your life. (In other words, it doesn't "
			       "exist.)\n");
		} else if (err == ENXIO) {
			printf("Have you ever tried to stick your finger in a wall outlet? "
			       "That's what putting a socket or device file here is like. "
			       "You should try it, it's fun!\n");
		} else if (err == EOVERFLOW) {
			printf("The file is too large to handle. Like the magnitude of "
			       "your parents' disappointment in you.\n");
		} else {
			printf("You are literally too stupid to insult. I can't even "
			       "figure out what you did wrong. It's time to sell your "
			       "computer and give up programming forever.\n");
		}
		return err;
	}
	
	char tape[TAPE_LENGTH] = {0};
	int err = interpret(input_file, &tape, stdin, stdout);
	if (err == 3) {
		printf("You tried to shift off the tape. But I guess that makes "
		       "sense, because you don't understand boundaries in real life"
		       " either. That's why you creep everyone out so much.");
	} else if (err == 2) {
		printf("I knew you were really dumb. Like, really, really, dumb. "
		       "But for some reason I thought that even you would be able"
		       " to count the number of [ and ] and make sure they matched"
		       ". Clearly, I was wrong.");
	} else if (err == 1) {
		printf("There are eight characters in this language. How could you "
		       "manage to fuck that up? Please, explain it to me, because I"
		       " actually don't get it.");
	}

	printf("\n");

	fclose(input_file);

	return err;
}

