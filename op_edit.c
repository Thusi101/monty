#include "monty.h"

/**
 * _popop - deletes the node at the top of the stack
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
		error_state.error = 1;
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
 * _swapop - swaps the first two at the top of the stack
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
		error_state.error = 1;
	}
	else
	{
		tmp = (*stack)->data;
		(*stack)->data = (*stack)->next->data;
		(*stack)->next->data = tmp;
	}
}
