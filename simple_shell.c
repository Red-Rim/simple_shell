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
			continue;
		}
		buffer[_strcspn(buffer, "\n")] = '\0';
		cmd = gettoks(buffer, " ");
		if (cmd == NULL)
		{
			perror("allocation failed");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		if (_strncmp("exit", *cmd, 4) == 0)
		{
			free(buffer);
			free(cmd);
			exit(EXIT_SUCCESS);
		}
		if (_strncmp("env", *cmd, 3) == 0)
		{
			_env();
			free(cmd);
			continue;
		}
		exc = _execve(cmd);
		if (exc == -1)
		{
			_putstr("./shell: No such file or directory\n");
			free(cmd);
			free(buffer);
			exit(EXIT_FAILURE);
		}
		free(cmd);

		free(buffer);
	}
	while (mode == 1 && exc == 0)

	return (0);
}
