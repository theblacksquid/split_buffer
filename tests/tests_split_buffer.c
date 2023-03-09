#include "../src/stack.h"
#include "../src/split_buffer.h"
#include <stdio.h>
#include <string.h>

int main ()
{
    printf("\n");
    
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

	string = "Yet one more example";

	for ( int index = 0; index < (int) strlen(string); index++ )
	    stack_push(testBuffer.tail, string[index]);
	
	stack_inspect(*testBuffer.tail);
	from_string = stack_to_string(*(testBuffer.tail), 0);
	printf("stack_to_string: %s\n", from_string);
	
	for ( int index = 0; index < (int) strlen(string); index++ )
	    printf("[%c]", from_string[index]);
	printf("\n");

	from_string = stack_to_string(*testBuffer.tail, 1);
	printf("stack_to_string reverse: %s\n", from_string);

	split_buffer_delete(&testBuffer);

	printf("split_buffer_new and split_buffer_delete pass\n");
    }

    testBuffer = split_buffer_new();

    char* example = "Sphinx of black quartz hear my vow";

    for ( int index = 0; index < (int) strlen(example); index++ )
	split_buffer_insert(&testBuffer, example[index]);

    if ( strcmp(example, split_buffer_to_string(testBuffer)) == 0 )
	printf("split_buffer_insert passes\n");
    else
	printf("split_buffer_insert fails\n");
    
    for ( int index = 0; index < 6; index++ )
	split_buffer_left(&testBuffer);

    char* head = stack_to_string(*testBuffer.head, 0);
    char* tail = stack_to_string(*testBuffer.tail, 1);

    if ( (strcmp(head, "Sphinx of black quartz hear ") == 0) &&
	 (strcmp(tail, "my vow") == 0)) 
	printf("split_buffer_left passes\n");
    else
	printf("split_buffer_left fails\n");

    for ( int index = 0; index < 6; index++ )
	split_buffer_right(&testBuffer);

    if ( strcmp(split_buffer_to_string(testBuffer), example) == 0 )
	printf("split_buffer_right passes\n");
    else
	printf("split_buffer_right fails\n");

    for ( int index = 0; index < 3; index++ )
	split_buffer_left(&testBuffer);

    char* to_append = "call";
    
    for ( int index = 0; index < 4; index++ )
	split_buffer_overwrite(&testBuffer, to_append[index]);

    if ( strcmp(split_buffer_to_string(testBuffer),
	        "Sphinx of black quartz hear my call") == 0 )
	printf("split_buffer_overwrite passes\n");

    split_buffer_delete(&testBuffer);
}
