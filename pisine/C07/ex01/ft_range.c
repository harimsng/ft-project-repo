#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*ret;
	int		idx;

	if (min >= max)
		return (0);
	ret = (int *)malloc(sizeof(int) * (max - min));
	idx = 0;
	while (min < max)
	{
		ret[idx] = min;
		++idx;
		++min;
	}
	return (ret);
}
