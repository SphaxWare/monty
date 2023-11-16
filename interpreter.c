#include "monty.h"

/**
 * main -main function or entry point
 * @argc: we dont care about it
 * @argv: string arguments to main
 * Return: 0
 */
int main(int argc, char *argv[])
{
	stack_t *stack;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	stack = NULL; /* initialize the stack */
	openfile(argv[1], &stack);
	return (EXIT_SUCCESS);
}

/**
 * openfile - this function open the file and read and
 * execute it line by line.
 * @filename: name of the file.
 * @stack: pointer to the stack.
 */
void openfile(char *filename, stack_t **stack)
{
	FILE *fptr;
	char buffer[SIZE], *token;
	int line_number = 0, i;

	instruction_t instructions[] = {
		{"push", push}, {"pall", pall}, {"pint", pint},
		{"nop", nop}, {"pop", pop}, { NULL, NULL}
	};
	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), fptr) != NULL)
	{
		line_number++;
		token = strtok(buffer, " \t\n");
		if (token == NULL)
			continue;
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(token, instructions[i].opcode) == 0)
			{
				instructions[i].f(stack, line_number);
				break;
			}
		}
		if (instructions[i].opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			free(*stack);
			stack = NULL;
			fclose(fptr);
			exit(EXIT_FAILURE);
		}
	}
	free(*stack);
	stack = NULL;
	fclose(fptr);
}
