#include "stack.h"
#include <stddef.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

stack_t stack_new()
{
    return (stack_t)
    {
	.nodes = NULL,
	.num_items = 0
    };
}

void stack_push(stack_t* stack, char data)
{
    node_t* new_node = calloc(1, sizeof(node_t));

    if ( new_node == NULL )
    {
	perror("Out of memory: stack_push\n");
	exit(1);
    }

    new_node->prev = stack->nodes;
    new_node->data = data;
    
    stack->nodes = new_node;
    stack->num_items++;
}

char stack_peek(stack_t stack)
{
    return stack.nodes->data;
}

char stack_pop(stack_t* stack)
{
    if ( stack->num_items > 0 )
    {
	char result = stack->nodes->data;
	node_t* to_delete = stack->nodes;
	stack->nodes = stack->nodes->prev;

	free(to_delete);
	stack->num_items--;

	return result;
    }

    else
	return '\0';
}

void stack_delete(stack_t* stack)
{
    node_t* previous = NULL;
    node_t* current = stack->nodes;
    
    for ( ; current != NULL ; )
    {
	previous = current;
	current = current->prev;
	free(previous);
    }

    stack->num_items = 0;
}

void stack_inspect(stack_t stack)
{
    printf("\n<TOP OF STACK>  ");
    
    for ( node_t* current = stack.nodes;
	  current != NULL;
	  current = current->prev )
    {
	printf("%c -> ", current->data);
    }

    printf("  <BOTTOM OF STACK>\n");
}

char* stack_to_string(stack_t stack, int reverse)
{
    char* result = calloc(stack.num_items + 1, sizeof(char));
    node_t* current = stack.nodes;
    
    if ( reverse > 0 )
    {
	for ( int index = 0; index < stack.num_items; index++ )
	{
	    result[index] = current->data;
	    current = current->prev;
	}
    }

    else
    {
	for ( int index = stack.num_items - 1; index > -1; index-- )
	{
	    /* printf("index: %d\n", index); */
	    result[index] = current->data;
	    current = current->prev;
	}
    }

    result[stack.num_items + 1] = '\0';

    return result;
}

void stack_swap(stack_t* stack)
{
    if ( stack->num_items > 1 )
    {
	char top = stack_pop(stack);
	char bottom = stack_pop(stack);
	stack_push(stack, top);
	stack_push(stack, bottom);
    }
}
