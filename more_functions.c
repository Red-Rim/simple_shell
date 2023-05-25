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
 * _strdup - Duplicates a string.
 * @str: The string to duplicate
 * Return: A pointer to the newly allocated duplicate string,
 * or NULL if memory allocation fails
 */
char *_strdup(char *str)
{
	size_t len = _strlen(str) + 1;
	char *duplicate = malloc(len * sizeof(char *));

	if (duplicate == NULL)
	{
		return (NULL);
	}

	return (_strcpy(duplicate, str));
}

/**
 * _isdigit - check a char if number
 * @a: interger
 * Return: 1 or 0
 */
int _isdigit(int a)
{
	if (a >= '0' && a <= '9')
	return (1);
	else
	return (0);
}

/**
 * _isstrdigit: check if astring is digit;
 * @str: string to check
 * Return: 1 in success or 0
 */

int _isstrdigit(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' && i == 0)
		{	i++;
			continue;
		}
		else if (!_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
