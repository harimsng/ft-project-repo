#include <stdlib.h>

char	*find_next(int (*thing)(char, char *), char *str, char *charset);
char	*ft_strndup(char *str, unsigned int size);
int		find_word(char c, char *charset);
int		find_delim(char c, char *charset);

char	**ft_split(char *str, char *charset)
{
	char			**ret;
	char			*temp;
	int				arr_len;
	int				idx;

	arr_len = 0;
	temp = str;
	while (*temp)
	{
		temp = find_next(find_word, temp, charset);
		if (!*temp)
			break;
		temp = find_next(find_delim, temp, charset);
		++arr_len;
	}
	ret = (char **)malloc(sizeof(char *) * (arr_len + 1));
	ret[arr_len] = 0;
	idx = 0;
	while (idx < arr_len)
	{
		temp = find_next(find_word, str, charset);
		str = find_next(find_delim, temp, charset);
		ret[idx++] = ft_strndup(temp, (unsigned int)(str - temp));
	}
	return (ret); 
}

char	*ft_strndup(char *str, unsigned int size)
{
	char			*ret;
	unsigned int	idx;

	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	idx = 0;
	while (idx < size)
	{
		ret[idx] = str[idx];
		++idx;
	}
	ret[idx] = 0;
	return (ret);
}

char	*find_next(int (*thing)(char, char *), char *str, char *charset)
{
	while (*str && thing(*str, charset))
		++str;
	return (str);
}

int	find_word(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		++charset;
	}
	return (0);
}

int	find_delim(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (0);
		++charset;
	}
	return (1);
}
