#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	int value;

	if (stack == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	value = atoi(strtok(NULL, " \t\n"));
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;

	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;

	free(new_node);
}

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}

}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
