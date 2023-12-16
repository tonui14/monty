#include "monty.h"
#define STACK_SIZE 4

/**
 * main - entry point for code
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 **/

int main(int argc, char *argv[])
{
	FILE *filePointer;
	stack_t *myStack = NULL;
	char *currentline = NULL;
	char *currentOpcode;
	char *currentArgument;
	unsigned int lineNumber = 0;
	size_t lineLength = 0;
	ssize_t bytesRead = 0;
	const char *DELIMITERS = " \t\n";

	if (argc != 2) /* Check for the correct number of arguments*/
	{
		fprintf(stderr, "USAGE; monty file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	filePointer = fopen(argv[1], "r"); /* Open the file if the argument is 1*/
	if (filePointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (bytesRead >= 0)  /* Read lines from the file*/
	{
		bytesRead = getline(&currentline, &lineLength, file pointer);
		lineNumber ++;
		currentOpcode = strtok(&currentline, DELIMITERS);

		if (bytesRead >= 0)
		{
			execute(currentline, &myStack, lineNumber, filePointer); /*there will be an execute function*/
			free(currentline);  /*Free the memory allocated for currentLine*/
		}
	}
	free_stack(myStack);
	fclose(filePointer); /*Close the file and free allocated memory*/
	return(0);
}

