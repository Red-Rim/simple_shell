#include "shell.h"
/**
 * _setenv - initialize a new env varbl or modify an existing one
 * @name: name of the env varbl
 * @value: value to set for the env varbl
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

/*------------------_unsetenv-------------------*/
/**
 * _unsetenv - remove an env varbl
 * @name: name of env varbl to unset
 * Return: 0 on success, -1 on filure
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
