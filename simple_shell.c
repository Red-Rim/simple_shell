#include "simple_shell.h"

/**
 * main - simlpe shell (UNIX command line interpreter)
 * Return: return 0 if succes
 */

int main(void)
{
	int mode = 1;
	char str[] = "#cisfun$ ";
	char *buffer;
	size_t bufsize = 1024;
	ssize_t read;
	char *tokens;

	buffer = malloc(bufsize * sizeof(char));
	{
		perror("allocation failed");
		exit(1);
	}

	while (mode)
	{
		mode r= isatty(STDIN_FILENO);
		if (mode == 1)
		{
			write(STOUT_FILENO, str, _strlen(str));
		}
		read = getline(&buffer, &bufsize, STDIN_FILENO);
		if (read == -1)
		{
			perror("failled to read");
			exit (2);
		}
		buffer(_strlen(buffer) - 1) = '\0';
		tokens =gettoks(buffer);




