#ifndef _MONTY_
#define _MONTY_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

#ifndef TRUE
#define TRUE 1
#ifndef FALSE
#define FALSE 0
#endif


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void clean_mem(void);
void exit_(int status);
void _execute(char *line, int line_num, stack_t **stack_values);
instruction_t *get_handlers(void);
void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, int n);
int _pop(stack_t **stack);
void enqueue(stack_t **stack, int n);
stack_t *get_top_element(stack_t **stack);
stack_t *get_bottom_element(stack_t **stack);
char **read_file(char *path, int *lines_count);
char *read_word(char *str, int *offset);


#endif
