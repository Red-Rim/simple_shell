#include "shell.h"

/**
 * _exit: exit shell
 * Return: void
 */

void _eexit(char **cmd, char *buffer, int a) 
{
	int b;
	if (cmd[1])
	{
		b = atoi(cmd[1]);
		/*if (_isstrdigit(cmd[1]) == 0)
			b = 2;*/
		perror("exit");
		if (b <= -1)
			b = 2;

		freetoken(cmd);
		free(buffer);
		exit(b);
	}
	freetoken(cmd);
	free(buffer);
	exit(a);
}
