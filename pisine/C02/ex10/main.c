#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	dest1[10];
	char	dest2[10];
	char	*src;
	int		size;
	int		idx;

	idx = 0;
	while (idx <  9)
	{
		dest1[idx] = idx + 'a';
		dest2[idx] = idx + 'a';
		++idx;
	}
	dest1[idx] = 0;
	dest2[idx] = 0;
	src = "12345";
	size = 9;
	printf("%lu\n", strlcpy(dest1, src, size));
	printf("%u\n", ft_strlcpy(dest2, src, size));
	printf("%s\n%s\n", dest1, dest2);
	return (0);
}
