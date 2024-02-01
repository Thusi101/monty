#include "monty.h"
/**
 * debug - debug function
 *
 * @args: array of arguments
 * @line_nb: line number
 */

void debug(char **args, int line_nb)
{
	int i = 0;

	printf("line[%d] = ", line_nb + 1);
	while (args && args[i])
	{
		printf("[%s] ", args[i]);
		i++;
	}
	printf("\n");
}
