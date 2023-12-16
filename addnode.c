#include "monty.h"

/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
 */
void addnode(stack_t **head, int n)
{
	stack_t *new_node, *swap;

	swap = *head;
	/*Use a while loop that always executes at least once*/
	while (1)
	{
		new_node = malloc(sizeof(stack_t));
		if (new_node == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		if (swap)
			swap->prev = new_node;
		new_node->n = n;
		new_node->next = *head;
		new_node->prev = NULL;
		*head = new_node;
		break; /* Exit the loop after the first iteration*/
	}
}
