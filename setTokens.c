#include "holberton.h"

/**
 * compareTokens - compare the arguments to exec commands
 * @tokens: Matrix of arguments
 * Return: function
 */

int compareTokens(char **tokens)
{
    printf("%s", tokens[0]);
    if (tokens[0] == NULL)
    {
        return (1);
    }
    /* Aqui deben compararse los tokens con los comandos ls, exit etc */
    return setCommand(tokens);
}

/**
 * setCommands - create pid and execute command
 * @tokens: Matrix of arguments
 * Return: int
 */

int setCommand(char **tokens)
{
    pid_t my_pid;    

    my_pid = fork();
    if (tokens && tokens[0])
    {
        if (my_pid < 0)
        {
            perror("Error");
        }
        else if (my_pid == 0)
        {
            if (execve(tokens[0], tokens, NULL) == -1)
            {
                perror("Error");
            }
            exit(EXIT_FAILURE);
        }
        else
        {
            wait(NULL);
        }
    }
    return (1);
}