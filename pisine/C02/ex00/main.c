#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src);

int	main(void)
{
	char	str[10];
	char	*dest;
	char	*src;

	dest = 0;
	src = "12345";
	strcpy(0, src);
	printf("%s\n", dest);
	dest = str;
	return (0);
}
