#include "shell.h"

/**
 * getlinebuffer - Retriieves a line of input from the user via standard input
 *
 * Return: The obtained input line as a null-terminated string,
 * or NULL if memory allocation fails.
 */

char *getlinebuffer(void)
{
	char *buffer;
	size_t bufsize = 1024;
	ssize_t read = 0;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer != NULL)
	{
		read = getline(&buffer, &bufsize, stdin);
		if (read == -1)
		{
			free(buffer);
			write(STDOUT_FILENO, "\n", _strlen("\n"));
			exit(0); /*exit on "EOF" */
		}
		buffer[_strcspn(buffer, "\n")] = '\0';
		return (buffer);
	}
	return (NULL);
}

/**
 * gettoks - function used to tokenize a string
 * @str: string
 * Return: tokens
 */

char **gettoks(char *str, char *deliminer)
{
	int i = 0;
	char **toks = malloc((MAX + 1) * sizeof(char **));
	char *token;

	token = strtok(str, deliminer);

	while (token != NULL && i < MAX)
	{
		toks[i] = malloc(_strlen(token) + 1);
		_strcpy(toks[i], token);
		token = strtok(NULL, deliminer);
		i++;
	}
	toks[i] = NULL;

	return (toks);

}

/**
 * freetoken - free token
 * @tok: string
 */

void freetoken(char **tok)
{
	int i = 0;

	while (tok[i] != NULL && i < MAX)
	{
		free(tok[i]);
		i++;
	}

	free(tok);
}
/**
 * cmnd_path - path of command
 * @command: command
 * Return: pointer or null
 */

char *cmnd_path(char *command)
{
	char *path_env = _getenv("PATH");
	char *dup = strdup(path_env);
	char *dir = strtok(dup, ":");

	while (dir != NULL)
	{
		size_t dir_len = _strlen(dir);
		size_t command_len = _strlen(command);
		size_t path_len = dir_len + 1 + command_len + 1;
		char *command_path = (char *)malloc(path_len);

	if (command_path != NULL)
	{
		_strcpy(command_path, dir);
		command_path[dir_len] = '/';
		_strcpy(command_path + dir_len + 1, command);
	if (access(command_path, X_OK) == 0)
	{
		free(dup);
		return (command_path);
	}
	free(command_path);
	}

	dir = strtok(NULL, ":");
	}
	free(dup);
	return (NULL);
}
/**
 * _execve - creat a process and execute a comand
 * @comnd: the command need to be executed
 * Return: 0 on success , -1 on error or 1 on any other error
 */
int _execve(char **comnd)
{
	char *path;
	pid_t pid;
	int status;

	path = cmnd_path(*comnd);
	if (path == NULL)
	path = *comnd;

	if (access(path, F_OK) == 0)
	{
		pid = fork();
	}
	if (pid == -1)
	{
		free(path);
		return (-1);
	}
	if (pid == 0)
	{
			if (execve(path, comnd, NULL) == -1)
			{
				free(path);
				freetoken(comnd);
				exit(EXIT_FAILURE);
			}
	}
	else
	{
		wait(&status);
	}
	}
	else
	{
		free(path);
		return (-1);
	}
	freetoken(comnd);
	return (0);
}
