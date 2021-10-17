#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strstr(char *str, char *to_find);

int	main(void)
{
//	char	dest1[10];
//	char	dest2[10];
//	char	*src;
//	int		idx;

	printf("%p\n", strstr("abcdef", "abc"));
	printf("%p\n", strstr("abcdef", "ac"));
	printf("%p\n", strstr("abcdef", ""));
//	printf("%p\n", strstr("abcdef", (void *)0));

	printf("%p\n", ft_strstr("abcdef", "abc"));
	printf("%p\n", ft_strstr("abcdef", "ac"));
	printf("%p\n", ft_strstr("abcdef", ""));
//	printf("%p\n", ft_strstr("abcdef", (void *)0));
	return (0);
}
