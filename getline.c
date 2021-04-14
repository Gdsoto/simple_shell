#include "holberton.h"

/**
 * main - main
 * @argc:pointer with number of arguments
 * @argv:pointer of array of arguments given
 * @env: environment variable
 * Return: return the function
 */
int main(int argv, char **argc, char **env)
{
	char *cwd;
	char *line;
	char **tokens;
	int status = 1;
	char s[100];
	(void)argc;
	(void)argv;

	while (status == 1)
	{
		cwd = getcwd(s, 100);
		p_cwd(cwd);
		line = getLines();
		tokens = getTokens(line);
		status = compareTokens(tokens, env);
	}
	free(line);
	free(tokens);
	return (0);
}

/**
 * getLines - obtain the arguments of command line
 * Return: *char of arguments
 */
char *getLines()
{
	char *line = NULL;
	size_t lineSize = 0;

	getline(&line, &lineSize, stdin);
	return (line);
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
