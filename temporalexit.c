#include "holberton.h"

/**
  * exitbuiltin - built in function to exit shell
  *
  * @tokens: arguments
  * @env: environment variables
  * Return: returns -1 to signal exit
  */
char exitbuiltin(char **tokens, char **env)
{
	int i = 0;
	(void)env;

	if (tokens && tokens[1])
	{
		i = atoi(tokens[1]);
		if (i <= 0)
		{
			i = -99;
			write(STDOUT_FILENO, "illegal number\n", 15);
		}
	}

	if (tokens)
		free2(tokens);

	return (i);
}
