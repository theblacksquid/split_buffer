LIBRARY_FILES= stack.c

tests:
	gcc ${LIBRARY_FILES} tests.c -o tests && ./tests && rm tests


