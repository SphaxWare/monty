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

void openfile(char *filename)
{
	FILE *fptr;
	char buffer[SIZE];

	fptr = fopen(filename, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), fptr) != NULL)
	{
		printf("%s", buffer);
	}
	fclose(fptr);
}
