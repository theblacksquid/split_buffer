#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char** argv)
{
    stack_t testStack = stack_new();

    if ( sizeof(testStack) == sizeof(stack_t) )
	printf("stack_new passes\n");

    stack_push(&testStack, 'A');

    if ( stack_peek(testStack) == 'A' )
	printf("stack_push and stack_peek pass\n");

    printf("begin stack_push stress test\n");

    char* example = "Nunc aliquet, augue nec adipiscing interdum, lacus tellus malesuada massa, quis varius mi purus non odio.";

    for ( int index = 0; index < (int) strlen(example); index++ )
    {
	stack_push(&testStack, example[index]);
    }

    if ( strcmp(stack_to_string(testStack, 0), example) )
	printf("stack_to_string passes\n");

    printf("%s\n", stack_to_string(testStack, 1));

    for ( int index = strlen(example) - 1; index > 0; index-- )
    {
	if ( stack_pop(&testStack) != example[index] )
	{
	    perror("stack_pop fail\n");
	    exit(1);
	}
    }

    printf("stack_pop passes\n");

    for ( int index = 0; index < (int) strlen(example); index++ )
    {
	stack_push(&testStack, example[index]);
    }

    stack_inspect(testStack);

    stack_delete(&testStack);

    stack_inspect(testStack);
}
