#include "shell.h"

/**
 * argc: test the argc
 * @a: argument
 * Return: void
 */

void argc(int argc, char *argv[])
{
	if (argc >= 2)
	{
		perror(argv[0]);
		exit(-1);
	}
}
