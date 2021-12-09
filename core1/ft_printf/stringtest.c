#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char	*str = "0123456789";
	printf("%d %d\n",
		printf("%s\n", str),
		ft_printf("%s\n", str)
	);
	printf("%d %d\n",
		printf("%5s\n", str),
		ft_printf("%5s\n", str)
	);
	printf("%d %d\n",
		printf("%.5s\n", str),
		ft_printf("%.5s\n", str)
	);
	printf("%d %d\n",
		printf("%2.5s\n", str),
		ft_printf("%2.5s\n", str)
	);
	printf("%d %d\n",
		printf("%5.2s\n", str),
		ft_printf("%5.2s\n", str)
	);
	printf("%d %d\n",
		printf("%5.5s\n", str),
		ft_printf("%5.5s\n", str)
	);
	printf("%d %d\n",
		printf("%15.5s\n", str),
		ft_printf("%15.5s\n", str)
	);
	printf("%d %d\n",
		printf("%5.15s\n", str),
		ft_printf("%5.15s\n", str)
	);
	printf("%d %d\n",
		printf("%15.15s\n", str),
		ft_printf("%15.15s\n", str)
	);
	return (0);
}
