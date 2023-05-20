#include "shell.h"

/*Red-Rim & Fatimazahraker*/

/*-------------------_strcpy----------------------*/
/**
 *_strcpy - copies the string pointer to src
 *@src: integer placed
 *@dest: integer entered
 *Return: Pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
		*(dest + i) = '\0';
		return (dest);
}

/*--------------------_strdup---------------------*/
/**
 */
char _strdup(const char *str)
{
	size_t len = strlen(str) + 1;
	char *duplicate = malloc(len);

	if (duplicate == NULL)
	{
		perror("allocation failed");
		return (NULL);
	}

	return (strcpy(duplicate, str));
}
