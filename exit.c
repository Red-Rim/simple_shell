#include "shell.h"

/**
 * _exit: exit shell
 * @cmd: command
 * @buffer: buffer
 * @a: integer status
 * Return: void
 */

void _eexit(char **cmd, char *buffer, int a)
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
		write(STDERR_FILENO, "Invalid arg for exit\n", _strlen("Invalid arg for exit\n"));
		}
	}
	freetoken(cmd);
	free(buffer);
	exit(exit_status);
}
