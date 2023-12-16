#include "monty.h"
/**
* execute - executes the opcode
* @myStack: head linked list - stack
* @lineNumber: part of the parameters
* @filePointer: poiner to monty file
* @currentline: line content
* Return: no return
*/
int execute(char *currentline, stack_t **myStack, unsigned int lineNumber, FILE *filePointer)
{
	instruction_t opcode_array[] = {{"push", f_push},/*Define an array of opcode structures*/
				{"pall", f_pall}, 
				{"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{NULL, NULL} /* Terminator indicating the end of the array*/
				};
	unsigned int i = 0;/* Initialize a loop control variable*/
	char *currentopcode;/* Declare variables to store opcode and argument*/
	char *currentArgument;

	currentopcode = strtok(currentline, " \n\t");/*Tokenize the current line to get the opcode*/
	if (currentopcode != NULL && currentopcode[0] == '#')/* Check if the opcode is a comment (#), and if so, return without executing*/
	{
		return (0);
	}
	currentArgument = strtok(NULL, " \n\t");/* Tokenize the current line again to get the argument*/
	for (unsigned int i = 0; opcode_array[i].opcode; i++)/* Loop through the opcode array to find a matching opcode*/
	{
		if (strcmp(currentopcode, opcode_array[i].opcode) == 0)/* If a matching opcode is found, call its associated function and return*/
		{	opcode_array[i].f(myStack, currentline);
			return (0);
		}
		i++;
	}
	if (currentopcode && opcode_array[i].opcode == NULL) /* If the loop exits and the opcode is not found, print an error message*/
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, currentopcode);
		fclose(filePointer);
		free(currentline);
		free_stack(*myStack);
		exit(EXIT_FAILURE); 
	}
	return (1);  /*Return 1 to indicate that the opcode was not found*/
}

