#include <stdio.h>
#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 *
 * @head: the head of the doubly linked list
 * @n: the value of the node to add
 *
 * Return: the new pointer
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new)
	{
		new->n = n;
		new->prev = NULL;
		if (*head)
			(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
	else
	{
		fprintf(stderr, "Error: malloc failed\n");
		META.error = 1;
	}

	return (new);
}

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 *
 * @head: the head of the doubly linked list
 * @n: the value of the node to add
 *
 * Return: the new pointer
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new = NULL;
	stack_t *cur = *head;

	new = malloc(sizeof(stack_t));
	if (new)
	{
		new->n = n;
		new->next = NULL;
		new->prev = NULL;

		if (!(*head))
			*head = new;
		else
		{
			while (cur->next)
				cur = cur->next;
			cur->next = new;
			new->prev = cur;
		}
	}
	else
	{
		fprintf(stderr, "Error: malloc failed\n");
		META.error = 1;
	}

	return (new);
}

/**
 * _push - adds a value at top (if in STACK mode)
 * or bottom (if in QUEUE mode) of stack
 *
 * @stack: the program stack
 * @line_nb: the line number
 * @a_value: value to add to stack
 */

void _push(stack_t **stack, unsigned int line_nb, char *a_value)
{
	size_t i = 0;

	while (a_value && a_value[i])
	{
		if (isdigit(a_value[i]) || (a_value[i] == '-' && strlen(a_value) > 1))
			i++;
		else
			break;
	}

	if (!a_value || *a_value == '\0' || i != strlen(a_value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_nb);
		META.error = 1;
		return;
	}

	if (META.state == STACK)
		add_dnodeint(stack, atoi(a_value));
	else
		add_dnodeint_end(stack, atoi(a_value));
}
