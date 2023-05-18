#include "shell.h"

 /*Red-Riml & Fatimazahraker*/
/**
 * main - simlpe shell (UNIX command line interpreter)
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 * Return: return 0 if succes
 */

int main(int argc, char *argv[])
{
	int mode = 1;
	char *buffer;
	size_t bufsize = 1024;
	ssize_t read;
	char **cmd;
	int exc;

	if (argc >= 2)
	{
		perror(argv[0]);
		exit(-1);
	}

	do {
		mode = isatty(STDIN_FILENO);
		if (mode == 1)
			write(STDOUT_FILENO, "#cisfun$ ", _strlen("#cisfun$ "));

		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("allocation failed");
			exit(1);
		}

		read = getline(&buffer, &bufsize, stdin);
		if (read == -1)
		{
			free(buffer);
			_putstr("\n");
			exit(0); /*exit on "EOF" */
		}
		buffer[_strcspn(buffer, "\n")] = '\0';
		cmd = gettoks(buffer);
		if (cmd == NULL)
		{
			free(buffer);
			perror("allocation failed");
			exit(1);
		}
		if (_strncmp("exit", cmd[0], 4) == 0)
		{
			free(buffer);
			exit(0);
		}
		exc = _execve(cmd);
	} while (mode == 1 && exc == 0);

	return (0);
}
