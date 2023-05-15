#include "shell.h"

/**
 * gettoks - function used to tokenize a string
 * @str: string
 * Return: tokens
 */

char **gettoks(char *str)
{
	int i = 0;
	const char *deliminer[] = " ";
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
