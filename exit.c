#include "shell.h"

/**
 * _exit: exit shell
 * @cmd: command
 * @buffer: buffer
 * @a: integer status
 * Return: void
 */

void _eexit(char **cmd, char *buffer,char *path, int a)
{
	int exit_status = a;

	if (cmd[1] != NULL)
	{
		if (_isstrdigit(cmd[1]))
		{
			exit_status = atoi(cmd[1]);
		}
		else
		{
		perror("Invalid arg for exit");
		}
	}
	if (path != NULL)
		free(path);
	freetoken(cmd);
	free(buffer);
	exit(exit_status);
}
