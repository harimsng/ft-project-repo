#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	str[10];
	char	*dest;
	char	*src;
	int		len;

	dest = str;
	src = "123091293";
	len = 5;
	ft_strncpy(dest, src, len);
	dest = str;
	return (0);
}
