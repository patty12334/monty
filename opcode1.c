#include "monty.h"

/**
 * _push - Pushes an element to the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */

void _push(stack_t **stack, unsigned int line_number)
{
	char *line = get_lines()[line_number - 1];
	char *opname = NULL, *arg = NULL, data_mode = DF_LIFO;
	int o = 0, arg_int = 0;

	opname = read_word(line, &o);
	arg = read_word(line, &o);
	free(opname);
	if ((arg != NULL) && is_integer(arg))
	{
		arg_int = atoi(arg);
		free(arg);
		data_mode = *get_data_mode();
		if (data_mode == DF_LIFO)
		{
			push(stack, arg_int);
		}
		else if (data_mode == DF_FIFO)
		{
			enqueue(stack, arg_int);
		}
	}
	else
	{
		if (arg != NULL)
			free(arg);
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit_(EXIT_FAILURE);
	}
}

/**
 * _pall - Prints all the values, starting from the top of the stack
 * @stack: The pointer to the stack of data
 * @line_number: The current line number
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;

	if (stack != NULL)
	{
		node = get_top_element(stack);
		while ((node != NULL))
		{
			printf("%d\n", node->n);
			node = node->prev;
		}
	}
	(void)line_number;
}
