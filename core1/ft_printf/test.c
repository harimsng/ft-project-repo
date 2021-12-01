#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/errno.h>
#include <stdint.h>

void	ft_putstr(const char *s);

int	main(void)
{
	uintptr_t 	ptr;
	int		test = 0;

	ptr = (uintptr_t)&test;
	printf("%d\n", (int)(((unsigned long long)&test) & 255));
	printf("%lx %p\n", ptr, &test);
	return (0);
}
