#include "monty.h"
/**
 * debug - debug function
 *
 * @args: array of arguments
 * @line_number: line number
 */

void debug(char **args, int line_number)
{
	int i = 0;

	printf("line[%d] = ", line_number + 1);
	while (args && args[i])
	{
		printf("[%s] ", args[i]);
		i++;
	}
	printf("\n");
}
