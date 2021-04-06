#include "holberton.h"

/**
 * main - main
 * @argc:pointer with number of arguments
 * @argv:pointer of array of arguments given
 * Return: return the function
 */

int main(int argc, char **argv)
{
    char *line; 
    (void)argc;
	(void)argv;
    
    while (1)
    {
        _putchar('$');
        _putchar(' ');
        line = getLines();
        printf("%s", line);

    }
    free(line);
    return(0);
}

/**
 * getLine - obtain the arguments of command line
 * Return: *char of arguments
 */

char *getLines()
{
    char *line = NULL;
	size_t lineSize = 0;

    getline(&line, &lineSize, stdin);
    return line;
}