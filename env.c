#include "shell.h"


/*Red_Rim & fatimazahraker */
/**
 * _env - print the environment variables
 * @cmd: commnd
 * @buffer: buffer
 * @path: path
 * @a: status
 * Return: void
 */

void _env(char **cmd, char *buffer, char *path, int a)
{
	int i;

	(void)a;
	(void)path;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freetoken(cmd, NULL, buffer);
}

/**
 * _getenv - get environement of PATH
 * @name: path name
 * Return: environement or NULL
 */
char *_getenv(char *name)
{
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
