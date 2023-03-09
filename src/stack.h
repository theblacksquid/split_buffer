#ifndef STACK_H
#define STACK_H

typedef struct node_t
{
    struct node_t* prev;
    char data;
} node_t;

typedef struct stack_t
{
    int num_items;
    node_t* nodes;
} stack_t;

stack_t stack_new();
void stack_delete(stack_t* stack);

void stack_inspect(stack_t stack);

void stack_push(stack_t* stack, char data);
char stack_peek(stack_t stack);
char stack_pop(stack_t* stack);
char* stack_to_string(stack_t stack, int reverse);
void stack_swap(stack_t* stack);

#endif
