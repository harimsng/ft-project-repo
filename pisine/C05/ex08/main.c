#include <stdio.h>
#include <time.h>

int		ft_ten_queens_puzzle(void);

int	main(void)
{
	clock_t	start, end;
	double	time;

	start = clock();
	printf("%d\n", ft_ten_queens_puzzle());
	end = clock();
	time = (double)(end - start) / (CLOCKS_PER_SEC);
	printf("time taken : %f\n", time);
	return (0);
}
