#include "monty.h"

/**
 * f_pop - prints the top
 * @head: stack head
 * @lineNumber: line_number
 * Return: no return
*/
void f_pop(stack_t **head, unsigned int lineNumber)
{
	stack_t *s;

	if (*head != NULL)
	{
		s = *head;
		*head = s -> next;
		free(s);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(filePointer);
		free(currentline);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}
