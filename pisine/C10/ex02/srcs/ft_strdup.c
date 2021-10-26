#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		idx;
	char	*ret;

	idx = 0;
	while (src[idx])
		++idx;
	ret = (char *)malloc(sizeof(char) * (idx + 1));
	idx = 0;
	while (src[idx])
	{
		ret[idx] = src[idx];
		++idx;
	}
	ret[idx] = 0;
	return (ret);
}
