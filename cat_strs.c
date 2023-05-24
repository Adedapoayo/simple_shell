#include "shell.h"

char* cat_strs(const char* first, ...)
{
	int ttl_len = 0;
	char* cated_str;
	char* ptr;
	const char* str;

	/* Determine the total length of the concatenated string*/
	va_list args;
    va_start(args, first);

    /* Get the length of the first string*/
    str = first;
    while (*str != '\0') {
        ttl_len++;
        str++;
    }

    /* Get the lengths of the remaining strings*/
    while ((str = va_arg(args, const char*)) != NULL)
    {
	    const char* curr = str;
        while (*curr != '\0') {
            ttl_len++;
            curr++;
        }
    }

    va_end(args);

    /* Allocate memory for the concatenated string*/
    cated_str = (char*)malloc((ttl_len + 1) * sizeof(char));

    /* Copy characters from the source strings to the concatenated string*/
    ptr = cated_str;
    str = first;
    while (*str != '\0') {
        *ptr = *str;
        ptr++;
        str++;
    }

    va_start(args, first);

    while ((str = va_arg(args, const char*)) != NULL) {
        const char* curr = str;
        while (*curr != '\0') {
            *ptr = *curr;
            ptr++;
            curr++;
        }
    }

    va_end(args);

    *ptr = '\0'; /* Add the null terminator at the end*/

    return cated_str;
}
