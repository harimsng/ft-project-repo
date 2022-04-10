#include <stdio.h>

void foo2(int *b)
{
	printf("foo2 : %d\n", *b);
	*b = 42;
}
