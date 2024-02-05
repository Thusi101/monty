#include "monty.h"

/**
 * _pop - deletes the node at the top of the stack
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _popop(stacknode **stack, unsigned int line_number)
{
	stacknode *tmp;

	if (!*stack || !stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		META.error = 1;
	}
	else if ((*stack)->next)
	{
		tmp = (*stack)->next;
		tmp->prev = NULL;
		free(*stack);
		*stack = tmp;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * _swap - swaps the first two at the top of the stack
 *
 * @stack: the program stack
 * @line_number: the line number
 */

void _swapop(stacknode **stack, unsigned int line_number)
{
	int tmp = 0;

	if (!*stack || !stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		META.error = 1;
	}
	else
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
}
