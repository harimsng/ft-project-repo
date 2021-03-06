#include "ft_printf.h"
#include <sys/errno.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int			test;
	char		*str = "1" "2" "3" "\n";

	printf("%d %d\n",
		ft_printf(str),
		printf(str));
// character
	printf("%d %d\n",
		ft_printf("abcdefg12345!@#$\n"),
		printf("abcdefg12345!@#$\n"));

	printf("%d %d\n",
		ft_printf("%c %c_%c_%c_%c\n", -255, -256, -257, 0, -1), 
		printf("%c %c_%c_%c_%c\n", -255, -256, -257, 0, -1)); 

	test = 0;
	printf("%d %d\n",
		ft_printf("%p\n", &test),
		printf("%p\n", &test));

	test = 121231434;
	printf("%d %d\n",
		ft_printf("%X\n", test),
		printf("%X\n", test));

	test = 121231434;
	printf("%d %d\n",
		ft_printf("%d\n", test),
		printf("%d\n", test));

	printf("%d %d\n",
		ft_printf("%s %s\n", NULL, "123"),
		printf("%s %s\n", NULL, "123"));

	printf("%d %d\n",
		ft_printf("1234__%d__abcd\n", INT_MIN),
		printf("1234__%d__abcd\n", INT_MIN));

	printf("%d %d\n",
		ft_printf("%% %%\n"),
		printf("%% %%\n"));

	printf("errno : %d\n", errno);
	printf("%s\n", strerror(errno));
	return (0);
}
