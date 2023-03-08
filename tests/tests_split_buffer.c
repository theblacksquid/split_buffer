#include "../src/stack.h"
#include "../src/split_buffer.h"
#include <stdio.h>

int main ()
{
    split_buffer_t testBuffer = split_buffer_init();

    if ( sizeof(testBuffer) == sizeof(split_buffer_t) )
	printf("split_buffer_init passes\n");
}
