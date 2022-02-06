#include <stdio.h>

void testfunc(void);
void		testfunc2(void);

void	testfunc(void)
{
	printf("static\n");
}

void	testfunc2(void)
{
	printf("non-static\n");
}
