#include "monty.h"

/**
 * _pop - deletes the node at the top of the stack
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _pop(dblink_t **dblink, unsigned int line_num)
{
	dblink_t *tmp;

	if (!*dblink || !dblink)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		FORM.error = 1;
	}
	else if ((*dblink)->fwd)
	{
		tmp = (*dblink)->fwd;
		tmp->bak = NULL;
		free(*dblink);
		*dblink = tmp;
	}
	else
	{
		free(*dblink);
		*dblink = NULL;
	}
}

/**
 * _swap - swaps the first two at the top of the stack
 *
 * @dblink: the program stack
 * @line_num: the line number
 */

void _swap(dblink_t **dblink, unsigned int line_num)
{
	int tmp = 0;

	if (!*dblink || !dblink || !(*dblink)->fwd)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		FORM.error = 1;
	}
	else
	{
		tmp = (*dblink)->n;
		(*dblink)->i = (*dblink)->fwd->i;
		(*dblink)->fwd->i = tmp;
	}
}
