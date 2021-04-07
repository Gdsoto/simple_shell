#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

/*Functions*/
int _putchar(char c);
char **getTokens(char *line);
char *getLines();
int main(int argc, char **argv);

#endif