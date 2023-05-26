#include "shell.h"

/**
 *
 *
 */

void _isatty()
{
	int mode;

	mode = isatty(STDIN_FILENO);
                if (mode == 1)
                        write(STDOUT_FILENO, "#cisfun$ ", _strlen("#cisfun$ "));
}
