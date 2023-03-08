#include "../src/stack.h"
#include "../src/split_buffer.h"
#include <stdio.h>
#include <string.h>

int main ()
{
    split_buffer_t testBuffer = split_buffer_new();

    if ( sizeof(testBuffer) == sizeof(split_buffer_t) )
    {
	char* string = "This is a test string";

	for ( int index = 0; index < (int) strlen(string); index++ )
	    stack_push(testBuffer.head, string[index]);
	
	stack_inspect(*testBuffer.head);
	char* from_string = stack_to_string(*(testBuffer.head), 0);
	printf("stack_to_string: %s\n", from_string);
	
	for ( int index = 0; index < (int) strlen(string); index++ )
	    printf("[%c]", from_string[index]);
	printf("\n");

	string = "Yet one";

	for ( int index = 0; index < (int) strlen(string); index++ )
	    stack_push(testBuffer.tail, string[index]);
	
	stack_inspect(*testBuffer.tail);
	from_string = stack_to_string(*(testBuffer.tail), 0);
	printf("stack_to_string: %s\n", from_string);
	
	for ( int index = 0; index < (int) strlen(string); index++ )
	    printf("[%c]", from_string[index]);
	printf("\n");

	from_string = stack_to_string(*testBuffer.tail, 1);
	printf("stack_to_string reverse: %s", from_string);
    }

    split_buffer_delete(&testBuffer);
}
