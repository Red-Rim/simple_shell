#include "shell.h"


/**
 * _env - print the environment variables
 * Return: 0 on success
 */

int _env(void)
{
	int i;
	extern char **environ;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}

/*------------------_getenv-------------------*/
/**
 * _getenv - get environement of PATH
 * @name: path name
 * Return: environement or NULL
 */
char *_getenv(char *name)
{
	extern char **environ;
	int length;
	int i;

	if (environ == NULL || name == NULL)
		return (NULL);

	length = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, length) == 0
				&& environ[i][length] == '=')
			return (&environ[i][length] + 1);
	}
		return (NULL);
}
