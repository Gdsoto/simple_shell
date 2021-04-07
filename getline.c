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
    char **tokens;
    (void)argc;
    (void)argv;

    while (1)
    {
        _putchar('$');
        _putchar(' ');
        line = getLines();
        tokens = getTokens(line);
        compareTokens(tokens);
    }
    free(line);
    free(tokens);
    return (0);
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

/**
 * getTokens - transform strin in tokens
 * @line:String of arguments
 * @delim: delimiter
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
    return tokens;
}