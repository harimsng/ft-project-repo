#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%d %d\n",
		printf("|%5c|\n", 'a'),
		ft_printf("|%5c|\n", 'a')
	);
	printf("%d %d\n",
		printf("|%-5c|\n", 'a'),
		ft_printf("|%-5c|\n", 'a')
	);
	printf("%d %d\n",
		printf("|%5c|\n", 127),
		ft_printf("|%5c|\n", 127)
	);
	printf("%d %d\n",
		printf("|%-5c|\n", 128),
		ft_printf("|%-5c|\n", 128)
	);
	printf("%d %d\n",
		printf("|%5c|\n", 0),
		ft_printf("|%5c|\n", 0)
	);
	printf("%d %d\n",
		printf("|%-5c|\n", -1),
		ft_printf("|%-5c|\n", -1)
	);
	printf("%d %d\n",
		printf("|%-5c|\n", 1),
		ft_printf("|%-5c|\n", 1)
	);
	printf("|%c|\n", 0);
	ft_printf("|%c|\n", 0);
	return (0);
}
