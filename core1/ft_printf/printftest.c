#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int			i;
	char		c;

	i = -256;
	c = (char)i;
//	printf("%d\n" ,printf("%02147483647d12345\n", 1));
	printf("|%zd|\n", write(1, &i, 1));
	printf("|%zd|\n", write(1, &c, 1));
	return (0);
}
