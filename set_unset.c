#include "shell.h"
/**
 * _setenv - initialize a new env varbl or modify an existing one
 * @name: name of the env varb
 * @value: value to set the env vabl
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value)
{
	int result;

	result = setenv(name, value, 1);
	if (result != 0)
	{
		perror("Error: failed to set env varbl");
		return (-1);
	}
	return (0);
}


/**
 * _unsetenv - remove an env varbl
 * @name: name of the env  varbl to unset
 * Return: 0 on success, -1 on failure
 */

int _unsetenv(const char *name)
{
	int result;

	result = unsetenv(name);
	if (result != 0)
	{
		perror("Error: failed to unset env varbl");
		return (-1);
	}
return (0);
}
/**
 * excunsetenv - execute unsetenv comnd
 * @cmd: comnd
 * @path: path
 * @buffer: buffer
 * return: void
 */
void excunsetenv(char **cmd, char *path, char *buffer)
{
	(void)path;
	if (_unsetenv(cmd[1]) == -1)
	{
		perror("Error: failed to unset env varbl");
	}
	freetoken(cmd, NULL, buffer);
}

/**
 * execseten - execute seten comnd
 * @cmd: comnd
 * @path: path
 * @buffer: buffer
 * return: void
 */

void execseten(char **cmd, char *path, char *buffer)
{
	(void)path;
	if (_setenv(cmd[1], cmd[2]) == -1)
	{
		perror("Error: failed to set varbl");
	}
	freetoken(cmd, NULL, buffer);
}

