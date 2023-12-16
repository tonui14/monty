#include "monty.h"

/**
 * if_numeric: function that checks if a string represents a numeric value
 * @str: pointer that dereferences the pointer string
 *
 **/

int if_numeric(const char *str)
{
	/*Check if the string is empty or NULL*/
	if (!str || *str == '\0')
	{
		/*Return 0 indicating that the string is not numeric*/
		return 0;
	}
	/*Iterate through each character in the string*/
	while (*str)
	{
		/*Check if the character is not a digit*/
		if (*str < '0' || *str > '9')
		{
			/*Return 0 indicating that the string is not numeric*/
			return 0;
		}
		/*Move to the next character in the string*/
		++str;
	}
	/*The string represents a numeric value, so return 1*/
	return 1;
}
