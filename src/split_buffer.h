#ifndef SPLIT_BUFFER_H
#define SPLIT_BUFFER_H

#include "stack.h"

typedef struct split_buffer_t
{
    stack_t* head;
    stack_t* tail;
    int size;
    int cursor;
}
split_buffer_t;

split_buffer_t split_buffer_new();
void split_buffer_delete(split_buffer_t* buffer);

void split_buffer_insert(split_buffer_t* buffer, char data);
void split_buffer_insert_after_cursor(split_buffer_t* buffer, char data);

void split_buffer_left(split_buffer_t* buffer);
void split_buffer_right(split_buffer_t* buffer);

char* split_buffer_head(split_buffer_t buffer);
char* split_buffer_tail(split_buffer_t buffer);
char* split_buffer_to_string(split_buffer_t buffer);

void split_buffer_overwrite(split_buffer_t* buffer, char data);

#endif
