#include "shell.h"
/**
 * stringcpy - compies a string
 * @dest: str1
 * @src: str2
 * return: void
 * */
void stringcpy(char *dest, const char *src)
{
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; /* Add null terminator at the end*/
}
