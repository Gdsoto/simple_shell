#include "holberton.h"
/**
 * getLines - obtain the arguments of command line
 * Return: *char of arguments
 */
char _getline(optype_t *data)
{
	static int characters;
	static char readed[BUFFER_SIZE];
	static char position;
	char *current_line;
	int i;
	ssize_t counter = 0;

	current_line = data->current_line;
	if (character == 0)
	{
		character = read(STDIN_FILENO, readed, sizeof(readed));
		position = readed;
	}

	if (character > 0)
	{
		for (i = 0;
				*position != '\n'
				&& *position != ';'
				&& (*position != '&' && *(position + 1) != '&')
				&& (*position != '|' && *(position + 1) != '|');
			i++)
			*current_line++ = *position++, character--, counter++;
		if (*position == ';')
		{
			data->logic_operator = true;
		}
		else
		{
			data->logic_operator = false;
		}
		*current_line = '\0', character--, position++;
		return (counter);
	}

	return (EOF);
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
