#include <stdlib.h>

int		initialize(int size, char **strs, char *sep, char **ret);
int		ft_strslen(int size, char **strs);
int		ft_mystrlen(char *str);
void	transfer(int size, char **strs, char *sep, char *ret);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;

	if (initialize(size, strs, sep, &ret) == 1)
		return (ret);
	transfer(size, strs, sep, ret);
	return (ret);
}

int	ft_strslen(int size, char **strs)
{
	int		len;
	int		idx;
	int		jdx;

	len = 0;
	idx = 0;
	while (idx < size)
	{
		if (strs[idx] == 0)
		{
			++idx;
			continue;
		}
		jdx = 0;
		while (strs[idx][jdx] != 0)
		{
			++jdx;
			++len;
		}
		++idx;
	}
	return (len);
}

int	ft_mystrlen(char *str)
{
	int		len;

	if (str == (void *)0)
		return (0);
	len = 0;
	while (str[len] != 0)
		++len;
	return (len);
}

int initialize(int size, char **strs, char *sep, char **ret)
{
	int		len;
	int		seplen;

	if (size == 0 || strs == (void *)0)
	{
		*ret = (char *)malloc(sizeof(char));
		**ret = 0;
		return (1);
	}
	seplen = ft_mystrlen(sep);
	len = ft_strslen(size, strs); 
	*ret = (char *)malloc(sizeof(char) * (len + seplen * (size - 1) + 1));
	return (0);
}

void	transfer(int size, char **strs, char *sep, char *ret)
{
	int		idx;
	int		jdx;
	int		sep_len;
	int		str_len;

	sep_len = ft_mystrlen(sep);
	idx = 0;
	while (idx < size)
	{
		jdx = 0;
		str_len = ft_mystrlen(strs[idx]);
		while (jdx < str_len)
			*(ret++) = strs[idx][jdx++];
		if (idx == size - 1)
			break;
		jdx = 0;
		while (jdx < sep_len)
			*(ret++) = sep[jdx++];
		++idx;
	}
	*ret = 0;
}
