#include "shell.h"

/*Red-Rim & Fatimazahraker*/

/*------------------_strlen-------------------*/
/**
 *_strlen - returns the length of a string
 *@s: integer entered
 *Return: void
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
	}
	return (i);
}

/*------------------_putchar-------------------*/

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 * Return: returns
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/*------------------_putstr--------------------*/

/**
 * _putstr - prints a string to stdout
 * @str: the string to be printed
 * Return: the numb of characters printed
 */
int _putstr(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
