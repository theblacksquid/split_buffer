#include "stack.h"
#include "split_buffer.h"
#include <stdlib.h>
#include <string.h>

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

void split_buffer_insert(split_buffer_t* buffer, char data)
{
    stack_push(buffer->head, data);
    buffer->cursor++;
    buffer->size++;
}

char* split_buffer_to_string(split_buffer_t buffer)
{
    char* head = stack_to_string(*buffer.head, 0);
    char* tail = stack_to_string(*buffer.tail, 1);
    int required_length = strlen(head) + strlen(tail) + 1;
    char* result = calloc(required_length, sizeof(char));
    strcat(result, head);
    strcat(result, tail);
    return result;
}

void split_buffer_left(split_buffer_t* buffer)
{
    if ( buffer->head->num_items > 0 )
    {
	stack_push(buffer->tail, stack_pop(buffer->head));
	buffer->cursor = buffer->head->num_items;
    }
}

void split_buffer_right(split_buffer_t* buffer)
{
    if ( buffer->tail->num_items > 0 )
    {
	stack_push(buffer->head, stack_pop(buffer->tail));
	buffer->cursor = buffer->head->num_items;
    }
}

void split_buffer_overwrite(split_buffer_t* buffer, char data)
{
    stack_pop(buffer->tail);
    stack_push(buffer->head, data);
}
