#ifndef HOLBERTON_H
#define HOLBERTON_H
#define TRUE (1 == 1)

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
int executeCommand(char **tokens, char **env);
int setCommand(char **tokens, char **env);
int compareTokens(char **tokens, char **env);
char **getTokens(char *line);
ssize_t _getline(data_t *data);
int main(int argc, char **argv, char **env);
char *_strdup(char *str);
int print_env(char **tokens, int *env);
int the_path(char *first, char **input, char **env, int *exit_stat);
char *path_string(char *right, char *first);
void print_string(char *s);
char *cpy_env(char **env);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int special_char(char *buffer, ssize_t bytes, int *exit_stat);
void built_ins(char *line, char **args, char **env, int *exit_stat);
void execute(int status, char **args, int *exit_stat, int *tal);
char **parser(char *l);
void print_int(int *tal);
void rm_newl(char *l);


#endif
