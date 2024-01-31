#include "monty.h"
/**
 * debug - debug function
 *
 * @args: array of arguments
 * @line_num: line number
 */

void debug(char **args, int line_num)
{
	int i = 0;

	printf("line[%d] = ", line_num + 1);
	while (args && args[i])
	{
		printf("[%s] ", args[i]);
		i++;
	}
	printf("\n");
}
