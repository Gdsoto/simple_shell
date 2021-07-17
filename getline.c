#include "holberton.h"
/**
 * getLines - obtain the arguments of command line
 * Return: *char of arguments
 */
char *getLines()
{
	char *buffer = NULL, *cp_buff = NULL;
	int position = 0, c = 0;

	buffer = _calloc(BUFSIZ, sizeof(char));
	if (!buffer)
	{
		perror("./hsh");
		exit(EXIT_FAILURE);
	}
	while ((c = _getchar()))
	{

		if (c == EOF)
		{
			buffer[position] = '\0';
			cp_buff = _strdup(buffer);
			free(buffer);
			return (cp_buff);
		}
		if (c == '\n')
		{
			buffer[position] = '\n';
			cp_buff = _strdup(buffer);
			free(buffer);
			return (cp_buff);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
	}
	return (NULL);
}
}

/**
 * getTokens - transform strin in tokens
 * @line: String of arguments
 * Return: matrix of tokens
 */
char **getTokens(char *line)
{
	int bufsize = BUFFSIZE_TOKENS, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		exit(EXIT_FAILURE);
	}
	token = strtok(line, DELIM_TOKENS);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, DELIM_TOKENS);
	}
	tokens[i] = NULL;
	return (tokens);
}
