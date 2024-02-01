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
	FILE *fp;

	META.error = 0;
	META.state = STACK;

	if (handle_input(argc, argv, &fp) == 1 || monty_run(fp) == 1)
	{
		if (fp)
			fclose(fp);
		exit(EXIT_FAILURE);
	}

	fclose(fp);
	return (EXIT_SUCCESS);
}
