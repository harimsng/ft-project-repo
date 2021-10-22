#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char	**str;
	int		idx;
	int		len;
	char	*arr[5] = {"123", "eee", "abcd", "!!!!", "{{{{}"};

	len = 5;
	str = (char **)malloc(sizeof(char *) * (len + 1));
	str[len] = 0;
	idx = 0;
	while (idx < len)
	{
		str[idx] = arr[idx];
		++idx;
	}
	while (*str)
		printf("%s\n", *str++);
	return (0);
}
