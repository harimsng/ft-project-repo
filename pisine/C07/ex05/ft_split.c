#include <stdio.h>
#include <stdio.h>

#include <stdlib.h>

int		find_next_thing(char **str, char *charset, int select);
int		get_len_alloc(char *str, char *charset, char **ret);
void	assign_elements(char *str, char *charset, char **ret);

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		len;

	printf("charset : ```%s'''\n", charset);
	printf("str : %s\n", str);
	len = get_len_alloc(str, charset, 0);
	ret = (char **)malloc(sizeof(char *) * (len + 1));
	get_len_alloc(str, charset, ret);
	assign_elements(str, charset, ret);
	return (ret);
}

// find next (including current character) thing
// select = 0 : find next non-sep character
// select = 1 : find next seperator
// ptr is used to avoid using double pointer str
int	find_next_thing(char **str, char *charset, int select)
{
	char	*ptr;
	int		len;
	int		idx;

	printf("find next select : %d\n", select);
	len = 0;
	ptr = *str;
	while (*ptr)
	{
		idx = 0;
		while (*ptr != charset[idx] && charset[idx])
			++idx;
		if ((charset[idx] != 0) == select)
			break ;
		++ptr;
		++len;
	}
	if (!(*ptr))
		return (0);
	*str = ptr;
	return (len);
}

// if ret is not given, it returns the size of the array for malloc.
// then it is given so that ret becomes array of strings(array of char pointers).
int	get_len_alloc(char *str, char *charset, char **ret)
{
	int		arr_len;
	int		str_len;

	arr_len = 0;
	while (*str)
	{
		if (find_next_thing(&str, charset, 1))
			break ;
		if (find_next_thing(&str, charset, 0))
			break ;
		str_len = find_next_thing(&str, charset, 1);
		if (str_len)
			break ;
		if (ret)
		{
			ret[arr_len] = (char *)malloc(sizeof(char) * (str_len + 1));
			printf("%d\n", arr_len);	
		}
		++arr_len;
	}
	if (ret)
		ret[arr_len] = 0;
	return (arr_len);
}

void	assign_elements(char *str, char *charset, char **ret)
{
	char	*assign;
	int		idx;
	int		str_len;

	while (*ret != 0)
	{
		find_next_thing(&str, charset, 1);
		find_next_thing(&str, charset, 0);
		assign = str;
		str_len = find_next_thing(&str, charset, 1);
		idx = 0;
		while (idx < str_len)
			(*ret)[idx++] = *(assign++);
		(*ret)[idx] = 0;
		++ret;
	}
}
