#include "shell.h"

/**
 * _strlen -  returns the length of a string.
 *@str: string to count
 * Return: 0
*/

int _strlen(char *str)
{
	int length = 0;

	while (*(str + length) != '\0')
	{
		length++;
	}
	return (length);

}
