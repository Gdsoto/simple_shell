#include "holberton.h"

/**
 * f_exit - Exit of simple shell
 * @tokens: Matrix of arguments
 * @env: environment variables
 * Return: 0
 */
int f_exit(char **tokens, char **env)
{
	(void)tokens;
	(void)env;
	return (0);
}

/**
 * f_cd - Change directory
 * @tokens: Matrix of arguments
 * @env:environment variable
 * Return: 1
 */
int f_cd(char **tokens, char **env)
{
	(void)env;

	if (tokens[1] == NULL)
	{
		perror("Error");
	}
	else
	{
		chdir(tokens[1]);
	}
	return (1);
}

/**
 * print_env - prints the environment variable
 * @tokens: the environment variable to print
 * @env: exit status
 * Return: Always (0) for sucess
 */
int print_env(char **tokens, int *env)
{
	unsigned int i = 0;

	while (tokens[i] != NULL)
	{
		print_string(tokens[i]);
		_putchar('\n');
		i++;
	}
	*env = 0;
	return (EXIT_SUCCESS);
}


/**
 * built_ins - function that implements the exit and print_env builtins
 * @line: the buffer
 * @args: the parsed arguments
 * @env: the environment
 * @exit_stat: the exit status
 * Return: void
 */
void built_ins(char *line, char **args, char **env, int *exit_stat)
{

	if (_strcmp(args[0], "exit") == 0)
	{
		free(args);
		free(line);
		exit(*exit_stat);
	}

	if (_strcmp(args[0], "env") == 0)
		print_env(env, exit_stat);
}
