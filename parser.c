#include"holberton.h"
/**
 * parser - function that takes a string from the command line and returns the
 * string as a parsed double pointer using a space as the delimiter
 * @l: Char pointer storing user input
 * Return: Char double pointer comprised of a char pointers that each contain
 * an argument
 */

char **parser(char *l)
{
	char **args;

	char *parsed = NULL;
	char *parsed2 = NULL;
	char *linecopy = NULL;

	int arg_num = 0, i = 0;

	linecopy = _strdup(l);
	parsed = strtok(linecopy, " \t");

	while (parsed != NULL)
	{
		arg_num++;
		parsed = strtok(NULL, " \t");
	}

	args = malloc(sizeof(char *) * (arg_num + 1));

	if (args == NULL)
		return (NULL);

	parsed2 = strtok(l, " \t");

	while (parsed2 != NULL)
	{
		args[i] = parsed2;
		parsed2 = strtok(NULL, " \t");
		i++;
	}

	args[i] = NULL;
	free(linecopy);
	return (args);
}
