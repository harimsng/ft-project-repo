#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	void			*ptr;
	int				num;
	long long int	addr;

	num = sizeof(ptr) * 9;
	ptr = &num;
	addr = (long long int)ptr;
	write(1, ptr, 1);
	write(1, "\n", 1);
	printf("%lld\n", addr);
	return (0);
}
