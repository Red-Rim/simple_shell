#include "shell.h"

 /*Red-Riml & Fatimazahraker*/
/**
 * main - simlpe shell (UNIX command line interpreter)
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 * Return: return 0 if succes
 */
int main()
{	char *buffer = NULL, *path = NULL;
	char **cmd = NULL;
	int exc = 0;

	while (1)
	{	_isatty();
		buffer = getlinebuffer();
		cmd = gettoks(buffer, " \t\n");
		if (*cmd == NULL)
		{	freetoken(cmd, path, buffer);
			continue; }
		if (_strncmp("exit", *cmd, 4) == 0 && *cmd != NULL)
			_eexit(cmd, buffer, path, exc);
		if (_strncmp("env", *cmd, 3) == 0 && *cmd != NULL)
		{	_env(cmd, buffer, path, exc);
			continue; }
		if (_strncmp("setenv", *cmd, 6) == 0 && cmd[1] != NULL && cmd[2] != NULL)
		{	execseten(cmd, path, buffer);
			continue; }
		if (_strncmp("unsetenv", *cmd, 8) == 0 && cmd[1] != NULL)
		{	excunsetenv(cmd, path, buffer);
		continue; }
		if (_strncmp("cd", *cmd, 2) == 0)
		{	execd(cmd, buffer, path);
			continue; }
		path = cmnd_path(*cmd);
		exc = _execve(cmd, path);
		if (exc != 0)
		{	perror("./shell");
			freetoken(cmd, path, buffer);
			continue; }
		freetoken(cmd, path, buffer); }
	return (0); }
