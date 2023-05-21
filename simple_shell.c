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
	char *buffer = NULL;
	size_t bufsize = 1024;
	ssize_t read = 0;
	char **cmd = NULL;
	int exc = 0;

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
			exit(EXIT_FAILURE);
		}

		read = getline(&buffer, &bufsize, stdin);
		if (read == -1)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", _strlen("\n"));
			exit(0); /*exit on "EOF" */
		}
		if (_strncmp("\n", buffer, 1) == 0)
		{
			free(buffer);
			continue;
		}
		buffer[_strcspn(buffer, "\n")] = '\0';
		cmd = gettoks(buffer, " ");
		if (cmd == NULL)
		{
			perror("allocation failed");
			free(buffer);
			continue;
		}
		if (_strncmp("exit", *cmd, 4) == 0)
		{
			freetoken(cmd);
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		if (_strncmp("env", *cmd, 3) == 0)
		{
			_env();
			freetoken(cmd);
			free(buffer);
			continue;
		}
		exc = _execve(cmd);
		if (exc == -1)
		{
			perror("./shell");
			freetoken(cmd);
			free(buffer);
			continue;
		}
		freetoken(cmd);
		free(buffer);
	}
	while (mode == 1 && exc == 0);

	return (0);
}
