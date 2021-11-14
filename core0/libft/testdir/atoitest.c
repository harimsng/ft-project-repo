#include "../libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*ptr;

	ptr = " \t\n\f\r\v123456789012345678901234567890";
	printf("%d\n", atoi(ptr));
	printf("%d\n", ft_atoi(ptr));
	ptr = " \t\n\f\r\v+12147483647";
	printf("%d\n", atoi(ptr));
	printf("%d\n", ft_atoi(ptr));
	ptr = " \t\n\f\r\v+12147483648";
	printf("%d\n", atoi(ptr));
	printf("%d\n", ft_atoi(ptr));
	ptr = " \t\n\f\r\v-2147483647";
	printf("%d\n", atoi(ptr));
	printf("%d\n", ft_atoi(ptr));
	ptr = " \t\n\f\r\v-2147483648";
	printf("%d\n", atoi(ptr));
	printf("%d\n", ft_atoi(ptr));
	ptr = " \t\n\f\r\v+9223372036854775807";
	printf("%d\n", atoi(ptr));
	printf("%d\n", ft_atoi(ptr));
	ptr = " \t\n\f\r\v+9223372036854775808";
	printf("%d\n", atoi(ptr));
	printf("%d\n", ft_atoi(ptr));
	ptr = " \t\n\f\r\v-9223372036854775808";
	printf("%d\n", atoi(ptr));
	printf("%d\n", ft_atoi(ptr));
	ptr = " \t\n\f\r\v-9223372036854775809";
	printf("%d\n", atoi(ptr));
	printf("%d\n", ft_atoi(ptr));

	return (0);
}
