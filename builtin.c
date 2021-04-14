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
 * f_env - Print environment variables
 * @tokens: pointer to string of tokens
 * @env: environment variables
 * Return: - 1
 */
int f_env(char **tokens, char **env)
{
	unsigned int i, j;
	(void)tokens;

	for (i = 0; env[i]; i++)
	{
		for (j = 0; env[i][j]; j++)
		{
		}
		write(STDOUT_FILENO, env[i], j);
		_putchar('\n');
	}
	return (1);
}

