#include "holberton.h"

/**
 * printdir - Prints the directory of the path found
 *
 * @path: String separated.
 *
 * Return: void
 */

void printdir(char *path)
{
  if (!path)
    return;

  while (*path)
    {
      if (*path != ':')
        write(STDOUT_FILENO, path, 1);
      else
        write(STDOUT_FILENO, "\n", 1);
      path++;
    }
}

/**
 * getenv - gets a matching env variable or returns NULL
 *
 * @name: name of env.
 * @env: env variables.
 *
 * Return: NULL; or contents that matching.
 */
char *getenv(const char *name, char **env)
{
  int i = 0, j = 0;

  while (env[j])
    {
      if (*(name + i) != environ[j][i])
        {
          if (!(*(name + i)) && environ[j][i] == '=')                                         
            return (cutenv(environ[j]));
          i = 0;
          j++;
        }
      else
        {
          i++;
        }
    }
  return (NULL);
}


/**
 * cutenv - cuts the environment variable to be only after the =
 *
 * @env: string of environment variable
 * Return: String Cut
 */

char *cutenv(char *env)
{
  while (*env != '=')
    env++;
  return (++env);
}


