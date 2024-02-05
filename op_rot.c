#include "monty.h"

/**
 * _rotlop - rotates the top of stack (top of stack becomes bottom)
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _rotlop(stacknode **stack, unsigned int line_number)
{
	stacknode *tmp;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		add_dnodeint_end(stack, (*stack)->n);
		tmp = (*stack)->next;
		tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * _rotrop - rotates the bottom of stack (bottom of stack becomes top)
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _rotrop(stacknode **stack, unsigned int line_number)
{
	stack_t *tmp;
	(void)line_number;

	if (*stack && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;

		add_dnodeint(stack, tmp->n);
		tmp = tmp->prev;
		free(tmp->next);
		tmp->next = NULL;
	}
}
