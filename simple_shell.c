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
	char str[] = "#cisfun$ ";
	char *buffer;
	size_t bufsize = 1024;
	ssize_t read;
	char **cmd;
	pid_t pid;
	int status;

	(void)argc;
	(void)argv;

	while (mode == 1)
	{
		mode = isatty(STDIN_FILENO);
		if (mode == 1)
			write(STDOUT_FILENO, str, _strlen(str));

		buffer = malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("allocation failed");
			exit(1);
		}

		read = getline(&buffer, &bufsize, stdin);
		if (read == -1)
		{
			perror("failled to read");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		buffer[_strcspn(buffer, "\n")] = '\0';
		cmd = gettoks(buffer);

	if (_strncmp("exit", cmd[0], 4) == 0)
	{
		free(buffer);
		free(cmd);
		exit(0);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		free(buffer);
		free(cmd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (access(cmd[0], F_OK) == 0)
		{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("execeve failed");
			free(cmd);
			free(buffer);
			_putstr("./shell: No such file or directory\n");
			exit(EXIT_FAILURE);
		}
		}
		else
		{
			_putstr("./shell: No such file or directory\n");
			free(cmd);
			free(buffer);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(cmd);
	}
	}
	return (0);
}
