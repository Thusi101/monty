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

	error_state.error = 0;
	error_state.state = STACK;

	if (handle_input(argc, argv, &file_ptr) == 1 || execute_monty(file_ptr) == 1)
	{
		if (file_ptr)
			fclose(file_ptr);
		exit(EXIT_FAILURE);
	}

	fclose(file_ptr);
	return (EXIT_SUCCESS);
}
