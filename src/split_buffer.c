#include "stack.h"
#include "split_buffer.h"
#include <stdlib.h>

split_buffer_t split_buffer_new()
{
    stack_t* head = calloc(1, sizeof(stack_t));
    stack_t* tail = calloc(1, sizeof(stack_t));
    *head = stack_new();
    *tail = stack_new();

    return (split_buffer_t)
    {
	.head = head,
	.tail = tail,
	.size = 0,
	.cursor = 0
    };
}

void split_buffer_delete(split_buffer_t* buffer)
{
    stack_delete(buffer->head);
    stack_delete(buffer->tail);
    buffer->cursor = -1;
    buffer->size = -1;
}

