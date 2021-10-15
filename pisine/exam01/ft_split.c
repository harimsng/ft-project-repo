#include <stdlib.h>

char	**null_return(void);

char	**ft_split(char *str)
{
	char	**ret;
	char	*word;
	int		arr_len;
	int		idx;
	int		jdx;
	int		word_len;
	int		word_flag;

	if (str == 0)
		return null_return();
	word = str; // use word as temp for now
	word_flag = 0;
	arr_len = 1; // one for null
	while (*str != 0)
	{
		if (!word_flag && *str != ' ' && *str != '\t' && *str != '\n')
		{
			word_flag = 1;
			++arr_len;
		}
		else if (*str == ' ' || *str == '\t' || *str == '\n')
			word_flag = 0;
		++str;
	}
	ret = (char **)malloc(sizeof(char *) * arr_len);
	idx = 0;
	while (idx < arr_len)
		ret[idx++] = NULL;
	str = word; // retrieve temp value
	idx = 0;
	while (idx < arr_len - 1)
	{
		while (*str != 0 && (*str == ' ' || *str == '\t' || *str == '\n'))
			++str;
		if (*str == 0)
			break;
		word = str;
		word_len = 1; // one for null
		while (*word != 0 && *str != ' ' && *str != '\t' && *str != '\n')
		{
			++word;
			++word_len;
		}
		ret[idx] = (char *)malloc(sizeof(char) * word_len);
		jdx = 0;
		while (*str != 0 && *str != ' ' && *str != '\t' && *str != '\n')
		{
			ret[idx][jdx] = *str;
			++str;
			++jdx;
		}
		++idx;
	}
	ret[idx] = NULL;
	return (ret);
}


char	**null_return(void)
{
	char	**ret;
	ret = (char **)malloc(sizeof(char *));
	*ret = NULL;
	return (ret);
}
