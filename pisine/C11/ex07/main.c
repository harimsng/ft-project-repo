#include <stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));
int		ft_strcmp(char *s1, char *s2);
int		ft_strrevcmp(char *s1, char *s2);
int		ft_strlencmp(char *s1, char *s2);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	ft_advanced_sort_string_tab(argv + 1, ft_strlencmp);
	++argv;
	while (*argv)
		printf("%s\n", *argv++);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strlencmp(char *s1, char *s2)
{
	int		len1;
	int		len2;
	
	len1 = 0;
	len2 = 0;
	while (s1[len1])
		++len1;
	while (s2[len2])
		++len2;
	return (len1 - len2);
}

int	ft_strrevcmp(char *s1, char *s2)
{
	int		idx;
	int		jdx;
	
	idx = 0;
	jdx = 0;
	while (s1[idx])
		++idx;
	while (s2[jdx])
		++jdx;
	--idx;
	--jdx;
	while (idx > 0 && jdx > 0 && s1[idx] == s2[jdx])
	{
		--idx;
		--jdx;
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[jdx]);
}
