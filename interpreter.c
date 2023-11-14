#include "monty.h"

/**
 * main - this is the main.
 * @argc:we dont care about it
 * @argv : w.
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	openfile(argv[1]);
	return (EXIT_SUCCESS);
}
/**
 * openfile - this function open the file and read and
 * execute it line by line.
 * @filename: name of the file.
 */
void openfile(char *filename)
{
	FILE *fptr;
	char buffer[SIZE], *token;
	int line_number = 0;

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), fptr) != NULL)
	{
		line_number++;
		printf("at line %d:%s", line_number, buffer);
		token = strtok(buffer, " \t\n");
		if (strcmp(token, "push") == 0)
		{
			/*push*/
			printf("%s\n", token);
			token = strtok(NULL, " \t\n");
			printf("%s\n", token);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
			exit(EXIT_FAILURE);
		}
	}
	fclose(fptr);
}
