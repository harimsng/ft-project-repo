#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int	g_num = 10;
int	*g_test = &g_num;

int	main(void)
{
	int		num = 0;
	int		*test = &num;

	if (fork() == 0)
	{
		printf("child test value = %d\n", *test);
		printf("child test g_value = %d\n", *g_test);
		++*test;
		++*g_test;
		printf("child test value = %d\n", *test);
		printf("child test g_value = %d\n", *g_test);
		return (0);
	}
	wait(NULL);
	printf("parent test value = %d\n", *test);
	printf("parent test g_value = %d\n", *g_test);
	++*test;
	++*g_test;
	printf("parent test value = %d\n", *test);
	printf("parent test g_value = %d\n", *g_test);
	return (0);
}
