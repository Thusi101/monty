#include "monty.h"

/**
 * _pint - prints the value from top of stack
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _pint(dblink_t **dblink, unsigned int line_num)
{
	if (!*dblink || !dblink)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		FORM.error = 1;
	}
	else
	{
		printf("%d\n", (*dblink)->i);
	}
}

/**
 * _pall - prints all values from stack, from top to bottom
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _pall(dblink_t **dblink, unsigned int line_num)
{
	dblink_t *cur = *dblink;
	(void)line_num;

	while (cur)
	{
		printf("%d\n", cur->i);
		cur = cur->fwd;
	}
}

/**
 * _nop - does absolutely nothing with nothing and prints nothing
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _nop(dblink_t **dblink, unsigned int line_num)
{
	(void)dblink;
	(void)line_num;
}

/**
 * _pchar - prints the value at top of stack as a char
 *
 * dblink: the program stack
 * @line_num: the line number
 */

void _pchar(dblink_t **dblink, unsigned int line_num)
{
	if (!*dblink || !dblink)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		FORM.error = 1;
	}
	else if ((*dblink)->i < 0 || (*dblink)->i > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		FORM.error = 1;
	}
	else
	{
		printf("%c\n", (*dblink)->i);
	}
}

/**
 * _pstr - prints the string starting at the top of the stack
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _pstr(dblink_t **dblink, unsigned int line_num)
{
	dblink_t *cur = *dblink;
	(void)line_num;

	while (cur && (cur->i > 0 && cur->i <= 127))
	{
		printf("%c", cur->i);
		cur = cur->fwd;
	}
	printf("\n");
}
