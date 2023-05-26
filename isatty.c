#include "shell.h"

/**
 * _isatty - execute isaty commd
 * return: void
 */

void _isatty(void)
{
	int mode;

	mode = isatty(STDIN_FILENO);
	if (mode == 1)
	write(STDOUT_FILENO, "#cisfun$ ", _strlen("#cisfun$ "));
}
