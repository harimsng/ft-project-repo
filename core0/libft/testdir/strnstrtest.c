#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1 = "121231212123";
	char	*s2 = "1212123";

	printf("%p\n", strnstr(s1, s2, 12)); 
	printf("%p\n", ft_strnstr(s1, s2, 12)); 

	printf("%p\n", strnstr(s1, s2, 11)); 
	printf("%p\n", ft_strnstr(s1, s2, 11)); 

	s1 = NULL;
	s2 = "1212123";
//	printf("%p\n", strnstr(s1, s2, 12)); 
	printf("%p\n", ft_strnstr(s1, s2, 2)); 

	s1 = "121231212123";
	s2 = NULL;
	printf("%p\n", strnstr(s1, s2, 12)); 
	printf("%p\n", ft_strnstr(s1, s2, 12)); 

	s1 = NULL;
	s2 = "1212123";
	printf("%p\n", strnstr(s1, s2, 0)); 
	printf("%p\n", ft_strnstr(s1, s2, 0)); 

	s1 = "121231212123";
	s2 = NULL;
	printf("%p\n", strnstr(s1, s2, 0)); 
	printf("%p\n", ft_strnstr(s1, s2, 0)); 

//	s1 = NULL;
//	s2 = NULL;
//	printf("%p\n", strnstr(s1, s2, 12)); 
//	printf("%p\n", ft_strnstr(s1, s2, 12)); 
	return (0);
}
