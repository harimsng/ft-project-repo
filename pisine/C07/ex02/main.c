#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int	main(void)
{
	int		*arr;
	int		min;
	int		max;
	int		idx;

	idx = 0;
	min = -1;
	max = 21;
	printf("%d %d\n", ft_ultimate_range(&arr, min, max), max - min);
	while (idx < max - min)
		printf("%d ", arr[idx++]);
	return (0);
}
