#include "simple_shell"

/**
 * gettoks - function used to tokenize a string
 * @str: string
 * Return: tokens
 */

char *gettoks(char *str)
{
	const char *deliminer[] = " ";
	char *token = strtok(str, deliminer);
	while (token != NULL)
	{
		char *toks = (char*) malloc(_strlen(token) + 1);
		strcpy(toks, token);
		token = strtok(NULL, deliminer);
		free(toks);
	}

	return(toks);
}

