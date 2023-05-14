#include "shell.h"

/**
 * gettoks - function used to tokenize a string
 * @str: string
 * Return: tokens
 */

char *gettoks(char *str)
{
	int i;
	const char *deliminer[] = " ";
	char **toks = malloc((MAX + 1) * sizeof(char *));
	char *token = strtok(str, deliminer);

	while (token != NULL)
	{
<<<<<<< HEAD
		toks[i] = (char*) malloc(_strlen(token) + 1);
		strcpy(toks[i], token);
=======
		char *toks = ((char*) malloc(_strlen(token) + 1));

		strcpy(toks, token);
>>>>>>> 5feb1211d13802961f847bdf629df0761e6926a2
		token = strtok(NULL, deliminer);
		i++;
	}
	toks[i] = NULL;

	return (toks);
}

