#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

/* Macros */
#define BUFFSIZE_TOKENS 64
#define DELIM_TOKENS " \n"

/**
 * struct optype - contain the data types to agree to function
 * @type: type of data to print
 * @func: The function associated
 */
typedef struct optype
{
    char *type;
    int (*func)();
} optype_t;

/*Functions*/
int _putchar(char c);
int _strcmp(char *str1, char *str2);
void p_cwd(char *cwd);
int f_exit(char **tokens, char **env);
int f_cd(char **tokens, char **env);
int f_env(char **tokens, char **env);
int setCommand(char **tokens, char **env);
int compareTokens(char **tokens, char **env);
char **getTokens(char *line);
char *getLines();
int main(int argc, char **argv, char **env);

#endif
