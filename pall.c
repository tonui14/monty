#include "monty.h"

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
