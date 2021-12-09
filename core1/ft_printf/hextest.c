#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	unsigned	num;

	num = 123456789;
	printf("%d %d\n",
		printf("%#x\n", num),
		ft_printf("%#x\n", num)
	);
	printf("%d %d\n",
		printf("%#x\n", 0),
		ft_printf("%#x\n", 0)
	);
	printf("%d %d\n",
		printf("%#6x\n", 0),
		ft_printf("%#6x\n", 0)
	);
	printf("%d %d\n",
		printf("%#x\n", 1),
		ft_printf("%#x\n", 1)
	);
	printf("%d %d\n",
		printf("%#6x\n", 1),
		ft_printf("%#6x\n", 1)
	);
	printf("%d %d\n",
		printf("%0#x\n", num),
		ft_printf("%0#x\n", num)
	);
	printf("%d %d\n",
		printf("%0#15x\n", num),
		ft_printf("%0#15x\n", num)
	);
	printf("%d %d\n",
		printf("%#15x\n", num),
		ft_printf("%#15x\n", num)
	);
	printf("%d %d\n",
		printf("%0#.15x\n", num),
		ft_printf("%0#.15x\n", num)
	);
	printf("%d %d\n",
		printf("%#.15x\n", num),
		ft_printf("%#.15x\n", num)
	);
	return (0);
}
