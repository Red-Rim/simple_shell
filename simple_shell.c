#include "shell.h"

 /*Red-Riml & Fatimazahraker*/
/**
 * main - simlpe shell (UNIX command line interpreter)
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 * Return: return 0 if succes
 */
int main()
{	char *buffer = NULL;
	char **cmd = NULL;
	int exc = 0, a = 0, mode = 1;
	char *path;

	while (1)
	{	mode = isatty(STDIN_FILENO);
		if (mode == 1)
			write(STDOUT_FILENO, "#cisfun$ ", _strlen("#cisfun$ "));
		buffer = getlinebuffer();
		buffer[_strcspn(buffer, "\n")] = '\0';
		cmd = gettoks(buffer, " \t\n");
		if (*cmd == NULL)
		{	free(buffer);
			freetoken(cmd);
			continue; }
		if (_strncmp("exit", *cmd, 4) == 0 && *cmd != NULL)
			_eexit(cmd, buffer, a);
		if (_strncmp("env", *cmd, 3) == 0 && *cmd != NULL)
		{	_env(cmd, buffer);
			continue; }
		if (_strncmp("setenv", *cmd, 6) == 0 && cmd[1] != NULL && cmd[2] != NULL)
		{
			if (_setenv(cmd[1], cmd[2]) == -1)
			{	perror("Error: Failed to set env varbl"); }
			freetoken(cmd);
			free(buffer);
			continue; }
		if (_strncmp("unsetenv", *cmd, 8) == 0 && cmd[1] != NULL)
		{
			if (_unsetenv(cmd[1] == -1)
			{	perroe("Error: Failed to unset env varbl"); }
				freetoken(cmd);
				free(buffer);
				continue; }
		path = cmnd_path(*cmd);
		exc = _execve(cmd, path);
		a = exc;
		if (exc != 0)
		{	perror("./shell");
			freetoken(cmd);
			free(buffer);
			if (path != NULL)
			free(path);
			continue; }
		if (path != NULL)
		free(path);
		freetoken(cmd);
		free(buffer); }
	return (0); }
