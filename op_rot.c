#include "monty.h"

/**
 * _rotl - rotates the top of stack (top of stack becomes bottom)
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _rotl(stack_t **stack, unsigned int line_nb)
{
	stack_t *tmp;
	(void)line_nb;

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
 * _rotr - rotates the bottom of stack (bottom of stack becomes top)
 *
 * @stack: the program stack
 * @line_nb: the line number
 */

void _rotr(stack_t **stack, unsigned int line_nb)
{
	stack_t *tmp;
	(void)line_nb;

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
