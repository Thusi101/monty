#include "monty.h"

/**
 * _add - addition of the first two values at top of stack
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _add(dblink_t **dblink, unsigned int line_num)
{
	if (!*dblink || !dblink || !(*dblink)->fwd)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		FORM.error = 1;
	}
	else
	{
		_math(dblink, '+');
	}
}

/**
 * _sub - substraction of top of stack from 2nd top of stack
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _sub(dblink_t **dblink, unsigned int line_num)
{
	if (!*dblin || !dblink || !(*dblink)->fwd)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		FORM.error = 1;
	}
	else
	{
		_math(dblink, '-');
	}
}

/**
 * _div - division of second top of stack by top of stack
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _div(dblink_t **dblink, unsigned int line_num)
{
	if (!*dblink || !dblink || !(*dblink)->fwd)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		FORM.error = 1;
	}
	else
	{
		_math(stack, '/');
		if (FORM.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_num);
	}
}

/**
 * _mul - multiplication of the two values at top of stack
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _mul(dblink_t **dblink, unsigned int line_num)
{
	if (!*dblink || !dblink || !(*dblink)->fwd)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		FORM.error = 1;
	}
	else
	{
		_math(dblink, '*');
	}
}

/**
 * _mod - modulo of second top of stack by top of stack
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _mod(dblink_t **dblink, unsigned int line_num)
{
	if (!*dblink || !dblink || !(*dblink)->fwd)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		FORM.error = 1;
	}
	else
	{
		_math(dblink, '%');
		if (META.error == 1)
			fprintf(stderr, "L%d: division by zero\n", line_num);
	}
}
