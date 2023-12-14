#include <stdio.h>
#include <stdlib.h>
#include <monty.h>

#define STACK_SIZE 4

int main()
{
	int selection;
	while (1)
	{
		printf("Carry out operations on stack");
		printf("\n1.Push\n2.Pop\n3.Show element\n4.End");
		printf("\n\n Enter selection");

		char input(50);
		scanf("%s", input);
		selection = atoi(input);
		
		if (selection == 1)
		{
			push();
		}
		else if (selection == 2)
		{
			pop();
		}
		else if (selection == 3)
		{
			show();
		}
		else if (selection == 4)
		{
			exit(0);
		}
		else
		{
			printf("\nInvalid choice!");
		}
	}
}_
