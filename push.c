#include "monty.h"

/**
 * f_push - Pushes an element onto the stack
 * @head: Pointer to the head of the stack
 * @lineNumber: Line number in the file
 **/

void f_push(stack_t **head, unsigned int lineNumber)
{
	int n;
	char *currentArgument;
	FILE *filePointer;
	char *currentline;
	/*Continue until a valid numeric argument is provided*/
	do
	{
		if (!currentArgument || !if_numeric(currentArgument))
		{
			fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
			fclose(filePointer);
			free(currentline);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		/*Convert currentArgument to an integer*/
		n = atoi(currentArgument);
		stack_t *myStack = NULL;
		lineLength = NULL;
		/*Add the integer to the stack using the addnode function*/
		/*If malloc fails, print an error message and exit*/
		if (!addnode(myStack, n))
		{
			fprintf(stderr, "Error: malloc failed\n");
			fclose(filePointer);
			free(currentline);
			free_stack(*myStack);
			exit(EXIT_FAILURE);
		}
		/*Get the next line in case currentArgument was not an integer*/
		free(currentline);
		currentline = NULL;
		if (getline(&currentline, &lineLength, filePointer) == -1)
		{
			fclose(filePointer);
			free(currentline);
			free_stack(*myStack);
			exit(EXIT_FAILURE);
		}
		currentArgument = strtok(currentline, " \n\t");
	}
	while (!if_numeric(currentArgument));
}

