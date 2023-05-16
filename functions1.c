#include "shell.h"


/**
 * gettoks - function used to tokenize a string
 * @str: string
 * Return: tokens
 */

char **gettoks(char *str)
{
	int i = 0;
	const char deliminer[] = " ";
	char **toks = malloc((MAX + 1) * sizeof(char **));
	char *token = strtok(str, deliminer);

	while (token != NULL && i < MAX)
	{
		toks[i] = malloc(_strlen(token) + 1);
		strcpy(toks[i], token);
		token = strtok(NULL, deliminer);
		i++;
	}
	toks[i] = NULL;

	return (toks);

}

/**
 * freetoken : free token
 * tok: string
 */

void freetoken(char **tok)
{
	int i = 0;

	while (tok != NULL && i < MAX)
	{
		free(tok[i]);
	}
	free(tok);
}

/**
 * _execve: creat a process and execute a comand
 * @comnd: the command need to be executed
 * Return: 0 on success , -1 on error or 1 on any other error
 */
int _execve(char **comnd)
{
	pid_t pid;
	int status;

	pid = fork();
        if (pid == -1)
        {
                perror("fork failed");
                exit(1);
        }
        else if (pid == 0)
        {
                if (access(comnd[0], F_OK) == 0)
                {
			if (execve(comnd[0], comnd, NULL) == -1)
			{
				perror("./shell");
				return(-1);
			}
                }
                else
                {
                        perror("./shell");
                        exit(1);
                }
        }
        else
        {
                wait(&status);

        }
	return (0);
}
