#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);

int	main(void)
{
	char	*str1;
	char	*str2;
	
	str1 = "abcdef";
	str2 = "abcdff";
	printf("%d ", strcmp(str1, str2));
	printf("%d\n", ft_strcmp(str1, str2));
	str1 = "";
	str2 = "abcdff";
	printf("%d ", strcmp(str1, str2));
	printf("%d\n", ft_strcmp(str1, str2));
	str1 = "A";
	str2 = "bcD";
	printf("%d ", strcmp(str1, str2));
	printf("%d\n", ft_strcmp(str1, str2));
	str1 = "\xff\xff";
	str2 = "\xff\xe";
	printf("%d ", strcmp(str1, str2));
	printf("%d\n", ft_strcmp(str1, str2));
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (*s1 == *s2 && *s1 != 0 && *s2 != 0)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
