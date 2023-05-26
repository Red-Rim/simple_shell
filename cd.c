#include "shell.h"

/**
 * _cd - change the current directory
 * @path: directory path to change to
 * Return: 0 on success, -1 on failure
 */
int _cd(const char *path)
{
	char cwd[PATH_MAX];

	if (chdir(path) != 0)
	{
		perror("chdir");
		return (-1);
	}

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		_setenv("PWD", cwd);
		return (0);
    }

    perror("getcwd");
    return -1;
}

/**
 *
 *
 */
void execd(char **cmd, char *buffer, char *path)
{
	(void)path;
	if (cmd[1] == NULL || _strncmp("-", cmd[1], 1) == 0)
                        {       char *home = _getenv("HOME");

                                if (home != NULL)
                                        _cd(home); }
                        else
                                _cd(cmd[1]);
			freetoken(cmd, NULL, buffer);
}
