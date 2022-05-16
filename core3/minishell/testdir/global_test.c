#include <stdio.h>

static const volatile	int	g_static_var = 5;
const volatile			int g_var = 15;

int	main(void)
{
	const int	var = 10;
	const volatile int	*ptr;
	int			*ptr2;

	printf("var test\n");
	printf("%d\n", var);
	ptr = &var;
	ptr2 = (int *)ptr;
	printf("ptr = %p, ptr2 = %p\n", ptr, ptr2);
	printf("val = %d, val2 = %d\n", *ptr, *ptr2);
	*ptr2 = 11;
	printf("\ng_var test\n");
	printf("%d\n", g_var);
	ptr = &g_var;
	ptr2 = (int *)ptr;
	printf("ptr = %p, ptr2 = %p\n", ptr, ptr2);
	printf("val = %d, val2 = %d\n", *ptr, *ptr2);
	*ptr2 = 16;
	printf("\ng_static_var test\n");
	printf("%d\n", g_static_var);
	printf("%d\n", g_static_var);
	ptr = &g_static_var;
	ptr2 = (int *)ptr;
	printf("ptr = %p, ptr2 = %p\n", ptr, ptr2);
	printf("val = %d, val2 = %d\n", *ptr, *ptr2);
	*ptr2 = 6;
	printf("%d\n", g_static_var);
	return (0);
}
