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
	int		test = -65;
	int		test2 = 54;
	char	*str = "123";

//	printf("%d\n", printf("|%0-0-   ++####+ 0+#09.5d|\n", test));
	printf("%d\n", printf("d|%2.3d|\n", test));
	printf("%d\n", printf("d|%+2.3d|\n", test2));
	printf("%d\n", printf("x|%0--#####11.15x|\n", test));
	printf("%d\n", printf("u|%--9.5u|\n", test));
	printf("%d\n", printf("c|%--9c|\n", test));
	printf("%d\n", printf("s|%--6.2s|\n", str));
	printf("%d\n", printf("p|%--19p|\n", str));
	printf("%d\n", printf("|%0-0-   ++####+ 0+#0.5|\n", str));

	printf("________________________________________\n");
	printf("%d\n", ft_printf("d|%2.3d|\n", test));
	printf("%d\n", ft_printf("d|%+2.3d|\n", test2));
	printf("%d\n", ft_printf("x|%0--#####11.15x|\n", test));
	printf("%d\n", ft_printf("u|%--9.5u|\n", test));
	printf("%d\n", ft_printf("c|%--9c|\n", test));
	printf("%d\n", ft_printf("s|%--6.2s|\n", str));
	printf("%d\n", ft_printf("p|%--19p|\n", str));
	printf("%d\n", ft_printf("|%0-0-   ++####+ 0+#0.5|\n", str));

	printf("%d %s\n", errno, strerror(errno));
	return (0);
}
