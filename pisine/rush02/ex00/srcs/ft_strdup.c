#include <stdlib.h>

char	*ft_strdup(char *str)
{
	int		idx;
	char	*ret;

	idx = 0;
	while (str[idx])
		++idx;
	ret = (char *)malloc(sizeof(char) * (idx + 1));
	idx = 0;
	while (str[idx])
	{
		ret[idx] = str[idx];
		++idx;
	}
	ret[idx] = 0;
	return (ret);
}
