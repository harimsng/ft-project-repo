#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int		idx;

	*range = (void *)0;
	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (*range == 0)
		return (-1);
	idx = 0;
	while (idx < max - min)
	{
		(*range)[idx] = min + idx;
		++idx;
	}
	return (max - min);
}
