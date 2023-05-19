#include "shell.h"


/**
 *
 *
 * */

 int _env(void)
{
	extern char **environ;
        int i;

        for (i= 0; environ[i] != NULL; i++)
        {
          
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		
		write(STDOUT_FILENO, "\n", 1);
	}
	return (0);
}
