#include "monty.h"

/**
 * _swap - Delete top of list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * _add - add the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _sub - substract the top two elements of the stack
 * @stack: Double linked list
 * @line_number: Line counter
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _divi - divide the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line counter
 */
void _divi(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	_pop(stack, line_number);
}

/**
 * _mul - multiplies the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}
