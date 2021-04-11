#include "holberton.h"

/**
 * compareTokens - compare the arguments to exec commands
 * @tokens: Matrix of arguments
 * Return: function
 */

int compareTokens(char **tokens, char **env)
{
    optype_t ops[] = {
        {"exit", f_exit},
        {"cd", f_cd},
        {"env", f_env},
        {'\0', NULL}};

    int i;

    if (tokens[0] == NULL)
    {
        return (1);
    }

    for (i = 0; i < 3; i++)
    {
        if (_strcmp(tokens[0], ops[i].type) == 0)
        {
            return ops[i].func(tokens, env);
        }
    }

    return setCommand(tokens, env);
}

/**
 * setCommands - create pid and execute command
 * @tokens: Matrix of arguments
 * Return: int
 */

int setCommand(char **tokens, char **env)
{
    pid_t my_pid;

    char *path = NULL;
    char filename[100] = "/bin/";

    my_pid = fork();
    if (tokens && tokens[0])
    {
        if (my_pid < 0)
        {
            perror("Error");
        }
        else if (my_pid == 0)
        {
            if ((tokens[0][0] == '/' || tokens[0][0] == '.') && tokens[0])
            {
                if (execve(tokens[0], tokens, NULL) == -1)
                    perror("Error");
                exit(EXIT_FAILURE);
            }
            else
            {
                path = strcat(filename, tokens[0]);

                if (execve(path, tokens, env) == -1)
                    perror("Error");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
        }
    }
    return (1);
}
