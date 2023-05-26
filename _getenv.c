#include "shell.h"
/**
 * _getenv - retrieve the value of env varbl
 * @name: name of the env varbl
 * Return: pointer to the value of the env varbl or NULL if not found
 */
char *_getenv(const char *name)
{
	return (getenv(name));
}
