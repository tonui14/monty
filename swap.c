#include "monty.h"

/**
 * f_swap - swaps the top two elements of the stack
 * @head: stack head pointer
 * @lineNumber: line_number
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int lineNumber)
{
	stack_t *s;
	int len = 0;
	int swap;

	s = *head;

	/* Calculate the length of the stack using a while loop */
	while (s)
	{
		s = s->next;
		len++;
	}

	/* Reset h to the head of the stack */
	s = *head;

	/* Check if the stack has at least two elements */
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(filePointer);
		free(currentline);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	/* Swap the top two elements of the stack using a while loop */
	while (s && s->next)
	{
		swap = s->n;
		s->n = s->next->n;
		s->next->s = aux;
		s = s->next;
	}
}
