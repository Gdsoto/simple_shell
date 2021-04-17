#include "holberton.h"

/**
 * the_path - function that prints environment PATH
 * @env: environment
 * @first: the first tokenized keyword (user inputted argument)
 * @input: the tokenized arguments
 * @exit_stat: the exit status
 * Return: 0 if successful
 */
int the_path(char *first, char **input, char **env, int *exit_stat)
{
	int i;
	char *temp, *left, *right;
	char *new = NULL, *envcopy = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		envcopy = _strdup(env[i]);
		left = strtok(envcopy, "= \t");
		temp = strtok(NULL, "= \t");

		if (_strcmp(left, "PATH") == 0)
		{
			right = strtok(temp, ": \t");
			while (right)
			{
				new = path_string(right, first);

				if (access(new, X_OK) == 0)
				{
					if (fork() == 0)
						execve(new, input, NULL);

					else
						wait(NULL);
					*exit_stat = 0;
					free(new);
					free(envcopy);
					return (0);
				}
				right = strtok(NULL, ": \t");
				free(new);
			}
		}
		free(envcopy);
	}
	return (2);
}
/**
 * path_string - function that prints the path string
 * @right: string after "PATH ="
 * @first: first tokenized word
 * Return: 0 for success
 */
char *path_string(char *right, char *first)
{
	char *new = NULL;
	char *token = NULL;
	int token_len = 0, first_len = 0;

	token = right;
	token_len = _strlen(token);
	first_len = _strlen(first);

	new = malloc((token_len + first_len + 2) * sizeof(char));
	if (new == NULL)
		return (NULL);

	new[0] = '\0';

	_strcat(new, right);
	_strcat(new, "/");
	_strcat(new, first);
	_strcat(new, "\0");

	return (new);
}
