#include <stdio.h>

void	ft_ft(int *nbr);

int	main(void)
{
	int		num;

	num = 2;
	printf("%d\n", num);
	ft_ft(&num);
	printf("%d\n", num);
	return (0);
}
