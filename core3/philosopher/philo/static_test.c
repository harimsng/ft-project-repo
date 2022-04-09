#include <stdio.h>

void	foo2(int *b);

static int b;

void	bar(int *a)
{
	printf("bar : %d\n", *a);
	*a = 10;
	printf("bar : %d\n", *a);
}

int	*foo(void)
{
	static int	a = 5;

	printf("foo : %d\n", a);
	bar(&a);
	b = 24;
	return (&b);
}

int	main(void)
{
	foo2(foo());
	printf("%d\n", b);
}
