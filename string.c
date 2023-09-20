#include "shell.h"

/**
 * _strlen - Compute the length of a string.
 * @s: The string whose length is to be determined.
 *
 * Return: The integer length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - Compare two strings lexicographically.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: A negative value if s1 < s2, a positive value
 * if s1 > s2, and 0 if s1 == s2.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Check if a string starts with a specified substring.
 * @haystack: The string to search.
 * @needle: The substring to find.
 *
 * Return: The address of the next character in haystack after the substring,
 * or NULL if not found.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - Concatenate two strings.
 * @dest: The destination buffer.
 * @src: The source buffer.
 *
 * Return: A pointer to the destination buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
