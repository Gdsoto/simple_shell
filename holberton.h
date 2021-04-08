#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/* Macros */
#define BUFFSIZE_TOKENS 64
#define DELIM_TOKENS " \n"

/*Functions*/
int _putchar(char c);
int setCommand(char **tokens);
int compareTokens(char **tokens);
char **getTokens(char *line);
char *getLines();
int main(int argc, char **argv);

#endif
