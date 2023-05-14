#include "shell.h"
 /*Red-Riml & Fatimazahraker*/
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
	char **cmd;
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
		buffer[_strcspn(buffer, "\n")] = '\0';
		cmd = gettoks(buffer);
	}
	if (_strncmp("exit", cmd[0], 4) == 0)
	{
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		free (buffer);
		free(cmd);
		exit(EXIT_FAILURE);
	}
	else if(pid == 0)
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("execeve failed");
			free(cmd);
			free(buffer);
			printf("./shell: No such file or directory")
			exit(EXIT_FAILURE);
		}
	}
	else 
	{
		wait();
	}
	}





