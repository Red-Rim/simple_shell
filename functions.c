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

/*-----------------_strncmp---------------------*/

/**
 * _strncmp - compares two strings up to a specified num of characters
 * @s1: first string to compare
 * @s2: second string to compare
 * @n: max numb of characters to compare
 * Return: an integer less than, equal to, or greater than zero if s1
 * is found, respectively, to be less than, to match, or be greater than s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	for (size_t i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}
	return (0);
}

/*-------------------_strcspn-------------------*/

/**
 * _strcspn - computes the length of the initial segment of s1 that consists
 * entirely of characters not contained in s2
 * @s1: the string to serch
 * @s2: the string containing the characters to match
 * Return: the length of the initial segment of s1 that consists entirely of
 * characters not contained in s2
 */
size_t _strcspn(const char *s1, const char *s2)
{
	const char *p1, *p2;

	for (p1 = s1; *p1 != '\0'; p1++)
	{
		for (p2 = s2; *p2 != '\0'; p2++)
		{
			if (*p1 == *p2)
			{
				return ((size_t)(p1 - s1));
			}
		}
	}
	return ((size_t)(p1 - s1));
}
