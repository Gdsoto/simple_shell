#include "holberton.h"

/**
 * compareTokens - compare the arguments to exec commands
 * @tokens: Matrix of arguments
 * @env: environment variable
 * Return: function
 */
int compareTokens(char **tokens, char **env)
{
	optype_t ops[] = {
		{"exit", f_exit},
		{"cd", f_cd},
		{"env", print_env,},
		{"\0", NULL}};
	int i;
	if (tokens[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < 3; i++)
	{
		if (_strcmp(tokens[0], ops[i].type) == 0)
		{
			return (ops[i].func(tokens, env));
		}
	}
	return (setCommand(tokens, env));
}

/**
 * setCommand - create pid and execute command
 * @tokens: Matrix of arguments
 * @env: environment variable
 * Return: int
 */
int setCommand(char **tokens, char **env)
{
	pid_t my_pid;
	int result = 0;
	my_pid = fork();

	if (tokens && tokens[0])
	{
		if (my_pid < 0)
		{
			perror("Error");
		}
		else if (my_pid == 0)
		{
			result = executeCommand(tokens, env);
		}
		else
		{
			wait(NULL);
		}
	}
	return (result);
}

/**
 * executeCommand - create pid and execute command
 * @tokens: Matrix of arguments
 * @env: environment variable
 * Return: int
 */

int executeCommand(char **tokens, char **env)
{
	char *path = NULL;
	char filename[100] = "/bin/";
	if ((tokens[0][0] == '/' || tokens[0][0] == '.') && tokens[0])
	{
		if (execve(tokens[0], tokens, NULL) == -1)
			perror("Error");
		exit(EXIT_FAILURE);
	}
	else
	{
		path = strcat(filename, tokens[0]);
		if (execve(path, tokens, env) == -1)
			perror("Error");
		exit(EXIT_FAILURE);
	}
	return (1);
}
