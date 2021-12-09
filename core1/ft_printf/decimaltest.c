#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("positive integer test\n");

	printf("%d %d\n"
			,printf("|%d|\n",12345678)
			,ft_printf("|%d|\n",12345678)
	);
	printf("+, ' ' flags test\n");
	printf("%d %d\n"
			,printf("|%+ d|\n",12345678)
			,ft_printf("|%+ d|\n",12345678)
	);
	printf("multiple + flags test\n");
	printf("%d %d\n"
			,printf("|%++d|\n",12345678)
			,ft_printf("|%++d|\n",12345678)
	);
	printf("+ flag test\n");
	printf("%d %d\n"
			,printf("|%+d|\n",12345678)
			,ft_printf("|%+d|\n",12345678)
	);
	printf("+, 0 flags test\n");
	printf("%d %d\n"
			,printf("|%+05d|\n",12345678)
			,ft_printf("|%+05d|\n",12345678)
	);
	printf("+05.3 test\n");
	printf("%d %d\n"
			,printf("|%+05.3d|\n",12345678)
			,ft_printf("|%+05.3d|\n",12345678)
	);
	printf("+05.6 test\n");
	printf("%d %d\n"
			,printf("|%+05.6d|\n",12345678)
			,ft_printf("|%+05.6d|\n",12345678)
	);
	printf("+05.11 test\n");
	printf("%d %d\n"
			,printf("|%+05.11d|\n",12345678)
			,ft_printf("|%+05.11d|\n",12345678)
	);
	printf("+012.4 test\n");
	printf("%d %d\n"
			,printf("|%+012.4d|\n",12345678)
			,ft_printf("|%+012.4d|\n",12345678)
	);
	printf("+012.11 test\n");
	printf("%d %d\n"
			,printf("|%+012.11d|\n",12345678)
			,ft_printf("|%+012.11d|\n",12345678)
	);
	printf("+012.13 test\n");
	printf("%d %d\n"
			,printf("|%+012.13d|\n",12345678)
			,ft_printf("|%+012.13d|\n",12345678)
	);
	printf("+015.13 test\n");
	printf("%d %d\n"
			,printf("|%+015.13d|\n",12345678)
			,ft_printf("|%+015.13d|\n",12345678)
	);
	printf("+015 test\n");
	printf("%d %d\n"
			,printf("|%+015d|\n",12345678)
			,ft_printf("|%+015d|\n",12345678)
	);
	printf("+0.15 test\n");
	printf("%d %d\n"
			,printf("|%+0.15d|\n",12345678)
			,ft_printf("|%+0.15d|\n",12345678)
	);
	printf("+015.8 test\n");
	printf("%d %d\n"
			,printf("|%15.8d|\n",12345678)
			,ft_printf("|%15.8d|\n",12345678)
	);
	printf("+015.9 test\n");
	printf("%d %d\n"
			,printf("|%+15.9d|\n",12345678)
			,ft_printf("|%+15.9d|\n",12345678)
	);
	printf("%d %d\n"
			,printf("|%d|\n",12345678)
			,ft_printf("|%d|\n",12345678)
	);
	printf(" , ' ' flags test\n");
	printf("%d %d\n"
			,printf("|%  d|\n",12345678)
			,ft_printf("|%  d|\n",12345678)
	);
	printf("multiple ' ' flags test\n");
	printf("%d %d\n"
			,printf("|%  d|\n",12345678)
			,ft_printf("|%  d|\n",12345678)
	);
	printf("  flag test\n");
	printf("%d %d\n"
			,printf("|% d|\n",12345678)
			,ft_printf("|% d|\n",12345678)
	);
	printf(" , 0 flags test\n");
	printf("%d %d\n"
			,printf("|% 05d|\n",12345678)
			,ft_printf("|% 05d|\n",12345678)
	);
	printf(" 05.3 test\n");
	printf("%d %d\n"
			,printf("|% 05.3d|\n",12345678)
			,ft_printf("|% 05.3d|\n",12345678)
	);
	printf(" 05.6 test\n");
	printf("%d %d\n"
			,printf("|% 05.6d|\n",12345678)
			,ft_printf("|% 05.6d|\n",12345678)
	);
	printf(" 05.11 test\n");
	printf("%d %d\n"
			,printf("|% 05.11d|\n",12345678)
			,ft_printf("|% 05.11d|\n",12345678)
	);
	printf(" 012.4 test\n");
	printf("%d %d\n"
			,printf("|% 012.4d|\n",12345678)
			,ft_printf("|% 012.4d|\n",12345678)
	);
	printf(" 012.11 test\n");
	printf("%d %d\n"
			,printf("|% 012.11d|\n",12345678)
			,ft_printf("|% 012.11d|\n",12345678)
	);
	printf(" 012.13 test\n");
	printf("%d %d\n"
			,printf("|% 012.13d|\n",12345678)
			,ft_printf("|% 012.13d|\n",12345678)
	);
	printf(" 015.13 test\n");
	printf("%d %d\n"
			,printf("|% 015.13d|\n",12345678)
			,ft_printf("|% 015.13d|\n",12345678)
	);
	printf(" 015 test\n");
	printf("%d %d\n"
			,printf("|% 015d|\n",12345678)
			,ft_printf("|% 015d|\n",12345678)
	);
	printf(" 0.15 test\n");
	printf("%d %d\n"
			,printf("|% 0.15d|\n",12345678)
			,ft_printf("|% 0.15d|\n",12345678)
	);
	printf(" 015.8 test\n");
	printf("%d %d\n"
			,printf("|%15.8d|\n",12345678)
			,ft_printf("|%15.8d|\n",12345678)
	);
	printf(" 015.9 test\n");
	printf("%d %d\n"
			,printf("|% 15.9d|\n",12345678)
			,ft_printf("|% 15.9d|\n",12345678)
	);
	printf("negative integer test\n");

	printf("%d %d\n"
			,printf("|%d|\n",-12345678)
			,ft_printf("|%d|\n",-12345678)
	);
	printf("+, ' ' flags test\n");
	printf("%d %d\n"
			,printf("|%+ d|\n",-12345678)
			,ft_printf("|%+ d|\n",-12345678)
	);
	printf("multiple + flags test\n");
	printf("%d %d\n"
			,printf("|%++d|\n",-12345678)
			,ft_printf("|%++d|\n",-12345678)
	);
	printf("+ flag test\n");
	printf("%d %d\n"
			,printf("|%+d|\n",-12345678)
			,ft_printf("|%+d|\n",-12345678)
	);
	printf("+, 0 flags test\n");
	printf("%d %d\n"
			,printf("|%+05d|\n",-12345678)
			,ft_printf("|%+05d|\n",-12345678)
	);
	printf("+05.3 test\n");
	printf("%d %d\n"
			,printf("|%+05.3d|\n",-12345678)
			,ft_printf("|%+05.3d|\n",-12345678)
	);
	printf("+05.6 test\n");
	printf("%d %d\n"
			,printf("|%+05.6d|\n",-12345678)
			,ft_printf("|%+05.6d|\n",-12345678)
	);
	printf("+05.11 test\n");
	printf("%d %d\n"
			,printf("|%+05.11d|\n",-12345678)
			,ft_printf("|%+05.11d|\n",-12345678)
	);
	printf("+012.4 test\n");
	printf("%d %d\n"
			,printf("|%+012.4d|\n",-12345678)
			,ft_printf("|%+012.4d|\n",-12345678)
	);
	printf("+012.11 test\n");
	printf("%d %d\n"
			,printf("|%+012.11d|\n",-12345678)
			,ft_printf("|%+012.11d|\n",-12345678)
	);
	printf("+012.13 test\n");
	printf("%d %d\n"
			,printf("|%+012.13d|\n",-12345678)
			,ft_printf("|%+012.13d|\n",-12345678)
	);
	printf("+015.13 test\n");
	printf("%d %d\n"
			,printf("|%+015.13d|\n",-12345678)
			,ft_printf("|%+015.13d|\n",-12345678)
	);
	printf("+015 test\n");
	printf("%d %d\n"
			,printf("|%+015d|\n",-12345678)
			,ft_printf("|%+015d|\n",-12345678)
	);
	printf("+0.15 test\n");
	printf("%d %d\n"
			,printf("|%+0.15d|\n",-12345678)
			,ft_printf("|%+0.15d|\n",-12345678)
	);
	printf("+015.8 test\n");
	printf("+015.8 test\n");
	printf("%d %d\n"
			,printf("|%15.8d|\n",-12345678)
			,ft_printf("|%15.8d|\n",-12345678)
	);
	printf("+015.9 test\n");
	printf("%d %d\n"
			,printf("|%+15.9d|\n",-12345678)
			,ft_printf("|%+15.9d|\n",-12345678)
	);
	return (0);
}
