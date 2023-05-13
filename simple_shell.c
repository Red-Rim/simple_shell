#include "simple_shell.h"

/**
 * main - simlpe shell (UNIX command line interpreter)
 * Return: return 0 if succes
 */

int main(int argc, char *argv[])
{
	int mode = 1;
	char str[] = "#cisfun$ ";
	char *buffer;
	size_t bufsize = 1024;
	ssize_t read;
	char *tokens;
	pid_t pid;

	buffer = malloc(bufsize * sizeof(char));
	{
		perror("allocation failed");
		exit(1);
	}

	while (mode == 1)
	{
		mode = isatty(STDIN_FILENO);
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
		tokens = gettoks(buffer);
	}
	if (_strncmp("exit", tokens[0], 4) == 0)
	{
		exit(1);
	}
	pid = fork();
	if (!pid)
	{
		if(exceve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			exit(1);
		}
		else
		{
			wait();
		}
	}





