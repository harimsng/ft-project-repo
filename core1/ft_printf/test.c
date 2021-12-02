#include "ft_printf.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/errno.h>
#include <stdint.h>

void	ft_putstr(const char *s);

int	main(void)
{
	int		test = 0;
	char	*str = "123";

	test = -65;
//	printf("%d\n", printf("|%0-0-   ++####+ 0+#09.5d|\n", test));
	printf("%d\n", printf("|%--++9.5d|\n", test));
	printf("%d\n", printf("|%--#####9.5x|\n", test));
	printf("%d\n", printf("|%--9.5u|\n", test));
	printf("%d\n", printf("|%--9c|\n", test));
	printf("%d\n", printf("|%--6.2s|\n", str));
	printf("%d\n", printf("|%--9p|\n", str));
	printf("%d\n", printf("|%0-0-   ++####+ 0+#09.5|\n", str));
/*
	printf("________________________________________\n");
	printf("%d\n", ft_printf("|%--++++9.5d|\n", test));
	printf("%d\n", ft_printf("|%--#####9.5x|\n", test));
	printf("%d\n", ft_printf("|%--9.5u|\n", test));
	printf("%d\n", ft_printf("|%--9c|\n", test));
	printf("%d\n", ft_printf("|%--9.5s|\n", str));
	printf("%d\n", ft_printf("|%--#9p|\n", str));
	printf("%d\n", ft_printf("|%0-0-   ++####+ 0+#09.5|\n", str));
*/
	printf("%d %s\n", errno, strerror(errno));
	return (0);
}
