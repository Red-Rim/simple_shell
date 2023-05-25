#include "shell.h"

 /*Red-Riml & Fatimazahraker*/
/**
 * main - simlpe shell (UNIX command line interpreter)
 * @argc: number of command-line arguments
 * @argv: array of command-line argument strings
 * Return: return 0 if succes
 */
int main(int argc, char *argv[])
{	int mode = 1;
	char *buffer = NULL;
	char **cmd = NULL;
	int exc = 0;
	int b, a;
	char *path;

	if (argc >= 2)
	{	perror(argv[0]);
		exit(-1); }
	do {	mode = isatty(STDIN_FILENO);
		if (mode == 1)
			write(STDOUT_FILENO, "#cisfun$ ", _strlen("#cisfun$ "));
		buffer = getlinebuffer();
		if (buffer == NULL)
		{	perror("allocation failed");
			free(buffer);
			exit(EXIT_FAILURE); }
		if (_strncmp("\n", buffer, 1) == 0)
		{	free(buffer);
			continue; }
		if (_strncmp("\t", buffer, 1) == 0)
		{	free(buffer);
			continue; }
		buffer[_strcspn(buffer, "\n")] = '\0';
		cmd = gettoks(buffer, " ");
		if (cmd == NULL)
		{	perror("allocation failed");
			continue; }
		if (_strncmp("exit", *cmd, 4) == 0 && *cmd != NULL)
		{
			if (cmd[1])
			{
				b = atoi(cmd[1]);
					if (b <= -1)
						b = 2;
				freetoken(cmd);
				free(buffer);
				exit(b);
			}
			freetoken(cmd);
			free(buffer);
			exit(a); }
		if (_strncmp("env", *cmd, 3) == 0 && *cmd != NULL)
		{	_env();
			freetoken(cmd);
			free(buffer);
			continue; }
		path = cmnd_path(*cmd);
		exc = _execve(cmd, path);
		a = exc;
		if (exc != 0)
		{	perror("./shell");
			exc = 0;
			continue; }
		if (path != NULL)
		free(path);
		freetoken(cmd);
		free(buffer); }
	while (mode == 1 && exc == 0);
	return (0); }
