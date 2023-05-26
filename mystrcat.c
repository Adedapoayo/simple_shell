#include "shell.h"

/**
 * _mystrcat - concatenates two strings.
 * @dest: output string
 * @src: the string to be appened
 * Return: dest
*/

char *_mystrcat(char *dest, char *src)
{
	int d, s;
	int v;

	d = s = 0;

	while (src[s] != '\0')
	{
		s++;
	}
	while (dest[d] != '\0')
	{
		d++;
	}
	for (v = 0; src[v] != '\0'; v++)
	{
		dest[d] = src[v];
		d++;
		s++;
	}
	dest[d] = '\0';
	return (dest);
}
