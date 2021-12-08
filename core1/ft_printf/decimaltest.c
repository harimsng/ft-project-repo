#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("positive integer test\n");

	printf("%d %d\n"
			,printf("|%+d|\n",12345678)
			,ft_printf("|%+d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+ d|\n",12345678)
			,ft_printf("|%+ d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%++d|\n",12345678)
			,ft_printf("|%++d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+d|\n",12345678)
			,ft_printf("|%+d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+05d|\n",12345678)
			,ft_printf("|%+05d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+05.3d|\n",12345678)
			,ft_printf("|%+05.3d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+05.6d|\n",12345678)
			,ft_printf("|%+05.6d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+05.11d|\n",12345678)
			,ft_printf("|%+05.11d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+012.4d|\n",12345678)
			,ft_printf("|%+012.4d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+012.11d|\n",12345678)
			,ft_printf("|%+012.11d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+012.13d|\n",12345678)
			,ft_printf("|%+012.13d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+015.13d|\n",12345678)
			,ft_printf("|%+015.13d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+015d|\n",12345678)
			,ft_printf("|%+015d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%15.8d|\n",12345678)
			,ft_printf("|%15.8d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%+15.9d|\n",12345678)
			,ft_printf("|%+15.9d|\n",12345678)
	);
	printf("negative integer test\n");

	printf("%d %d\n"
			,printf("|%d|\n",-12345678)
			,ft_printf("|%d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|% d|\n",-12345678)
			,ft_printf("|% d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%+d|\n",-12345678)
			,ft_printf("|%+d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%d|\n",-12345678)
			,ft_printf("|%d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%05d|\n",-12345678)
			,ft_printf("|%05d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%05.3d|\n",-12345678)
			,ft_printf("|%05.3d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%05.6d|\n",-12345678)
			,ft_printf("|%05.6d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%05.11d|\n",-12345678)
			,ft_printf("|%05.11d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%012.4d|\n",-12345678)
			,ft_printf("|%012.4d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%012.11d|\n",-12345678)
			,ft_printf("|%012.11d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%012.13d|\n",-12345678)
			,ft_printf("|%012.13d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%015.13d|\n",-12345678)
			,ft_printf("|%015.13d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%015d|\n",-12345678)
			,ft_printf("|%015d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%15.8d|\n",-12345678)
			,ft_printf("|%15.8d|\n",-12345678)
	);
	printf("%d %d\n"
			,printf("|%15.9d|\n",-12345678)
			,ft_printf("|%15.9d|\n",-12345678)
	);
	return (0);
}
