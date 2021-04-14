#include "holberton.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: character.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strcmp - Compares strings str1 & str2
 * @str1: First string to be compared
 * @str2: Second string being compared with the first
 * Return: 0
 */
int _strcmp(char *str1, char *str2)
{
	int i, result = 0;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		result = str1[i] - str2[i];
		if (result != 0)
		{
			return (result);
		}
		else
		{
			continue;
		}
	}
	return (result);
}

/**
 * p_cwd - print current working directory
 * @cwd: string of cwd
 * Return: void
 */
void p_cwd(char *cwd)
{
	int i;

	for (i = 0; cwd[i] != '\0'; i++)
	{
		_putchar(cwd[i]);
	}
	_putchar('$');
	_putchar(' ');
}

