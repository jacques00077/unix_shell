#include "shell.h"

/**
 * bfree - Deallocates memory pointed to by a pointer and sets it to NULL
 * @ptr: Address of the pointer to free
 *
 * Return: 1 if memory was freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
