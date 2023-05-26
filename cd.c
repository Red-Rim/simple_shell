#include "shell.h"

/**
 * _cd - change the current directory
 * @path: directory path to change to
 * Return: 0 on success, -1 on failure
 */
int _cd(const char *path)
{
	int result = chdir(path);
	if (result != 0)
	{
		perror("Error: failed to change directory");
		return (-1);
	}

	char cwd[PATH_MAX];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		_setenv("PWD", cwd);

	return (0);
}
