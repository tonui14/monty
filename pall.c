#include "monty.h"

/**
 * f_pall - prints all elements in the stack
 * @head: pointer to the head of the stack
 * @lineNumber: line number in the file
 *
 **/

void f_pall(stack_t **head, unsigned int lineNumber)
{
	stack_t *s;

	//Suppress unused variable
	(void)lineNumber;
	s = *head;

	// Iterates through the stack and print each element
	while (s != NULL)
	{
		printf("%d\n", s->n);
		s = s->next;
	}
}
