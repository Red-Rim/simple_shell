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
	int b;
	char *path;

/*	argc(argc, argv);*/
	do {	mode = isatty(STDIN_FILENO);
		if (mode == 1)
			write(STDOUT_FILENO, "#cisfun$ ", _strlen("#cisfun$ "));
		buffer = getlinebuffer();
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
<<<<<<< HEAD
		{
			/**if (cmd[1])
			{
				b = atoi(cmd[1]);
					if (b <= -1)
						b = 2;
				exit(b);
			}*/
			freetoken(cmd);
			free(buffer);
			exit(0); }
=======
			_eexit(cmd, buffer, a);
>>>>>>> 9d1849a9ecbc075861e326dddc09b38aa0b2c51f
		if (_strncmp("env", *cmd, 3) == 0 && *cmd != NULL)
		{	_env();
			continue; }
		path = cmnd_path(*cmd);
		exc = _execve(cmd, path);
		if (exc == -1)
		{	perror("./shell");
			exc = 0;
			continue; }
		if (path == NULL)
		free(path);
		freetoken(cmd);
		free(buffer); }
	while (mode == 1 && exc == 0);
	return (0); }
