#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*ret;

	len = 0;
	while (src[len] != 0)
		++len;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == 0)
		return (0);
	while (*src != 0)
	{
		*ret = *src;
		++ret;
		++src;
	}
	*ret = 0;
	return (ret - len);
}
