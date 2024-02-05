#include "monty.h"

/**
 * main - entry point of our monty program
 * @argc: the amount of arguments given to the program
 * @argv: the array of arguments given to the program
 *
 * Return: EXIT_SUCCESS if no error has occures, otherwise EXIT_FAILURE
 */

int main(int argc, char **argv)
{
	FILE *file_ptr;

	META.error = 0;
	META.state = STACK;

	if (handle_input(argc, argv, &file_ptr) == 1 || monty_run(file_ptr) == 1)
	{
		if (fle_ptr)
			fclose(file_ptr);
		exit(EXIT_FAILURE);
	}

	fclose(file_ptr);
	return (EXIT_SUCCESS);
}
