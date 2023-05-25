#include "shell.h"

/*Red-Rim & fatimazahraker*/
/**
 * _setenv - initialize a new env variable or modify an existing one
 * @name: name of variable
 * @value: value to set for variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value)
{
	if (name == NULL || value == NULL)
	return (-1);

	int result = setenv(name, value, 1);

	if (result == -1)
	{
	perror("setenv");
	return (-1);
	}
	return (0);
}

/*-----------------_unsetenv-------------------*/
/**
 * _unsetenv - remove an env variable
 * @name: name of variable to remove
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	if (name == NULL)
		return (-1);

	int result = unsetenv(name);

	if (result == -1)
	{
		perror("unsetenv");
		return (-1);
	}
	return (0);
}
