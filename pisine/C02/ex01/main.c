#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	dest1[10] = {'0',};
	char	dest2[10] = {'0',};
	char	*src;
	int		len;

	src = "12393";
	len = 5;
	printf("%s\n", strncpy(dest1, src, len));
	printf("%s\n", ft_strncpy(dest2, src, len));
	src = "12393";
	len = 10;
	printf("%s\n", strncpy(dest1, src, len));
	printf("%s\n", ft_strncpy(dest2, src, len));
	src = "12393";
	len = 2;
	printf("%s\n", strncpy(dest1, src, len));
	printf("%s\n", ft_strncpy(dest2, src, len));
	src = "12393";
	len = 8;
	printf("%s\n", strncpy(dest1, src, len));
	printf("%s\n", ft_strncpy(dest2, src, len));
	return (0);
}
