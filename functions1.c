#include "shell.h"


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

	while (tok != NULL && i < MAX)
	{
		free(tok[i]);
	}
	free(tok);
}

/**
<<<<<<< HEAD
 * _getenv - get environement of  PATH
 * @name: path name
 * Return: environement or NULL
 */
char*  _getenv(char* name)
{
	extern char **environ;
	int length;
	int i;

	if (environ == NULL || name == NULL)
		return NULL;

	length = _strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, length) == 0
				&& environ[i][length] == '=')
			return (&environ[i][length] + 1);
	}
	return (NULL);
}

/**
 * cmnd_path - path of command
 * @command: command
 * Return: pointer or null
 */

char* cmnd_path(char* command)
{
	char* path_env = _getenv("PATH");
	char* dir = strtok(path_env, ":");

    while (dir != NULL)
    {
        size_t dir_len = _strlen(dir);
        size_t command_len = _strlen(command);
        size_t path_len = dir_len + 1 + command_len + 1;
        char* command_path = (char*)malloc(path_len);

        if (command_path != NULL)
	{
            _strcpy(command_path, dir);
            command_path[dir_len] = '/';
            _strcpy(command_path + dir_len + 1, command);

            if (access(command_path, X_OK) == 0)
	    {
                return command_path;
            }

            free(command_path);
        }

        dir = strtok(NULL, ":");
    }

    return NULL;
}
/**
 * _execve: creat a process and execute a comand
=======
 * _execve - creat a process and execute a comand
>>>>>>> 2ff368f4952db44ab3b8bdab510bf1daa09acd44
 * @comnd: the command need to be executed
 * Return: 0 on success , -1 on error or 1 on any other error
 */
int _execve(char* comnd,char** cmd)
{
	char *path;
	pid_t pid;
	int status;


	path = cmnd_path(comnd);
	if (path == NULL)
	path = comnd;

	pid = fork();
<<<<<<< HEAD
        if (pid == -1)
        {
                perror("fork failed");
                exit(1);
        }
        else if (pid == 0)
        {
                if (access(path, F_OK) == 0)
                {
			if (execve(path, cmd, NULL) == -1)
=======
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
>>>>>>> 2ff368f4952db44ab3b8bdab510bf1daa09acd44
			{
				perror("./shell");
				return (-1);
			}
<<<<<<< HEAD
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

	free(path);
=======
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
>>>>>>> 2ff368f4952db44ab3b8bdab510bf1daa09acd44
	return (0);
}
