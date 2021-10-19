#include <stdio.h>
#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(void)
{
	char	*nbr;
	char	*bf;
	char	*bt;
	char	*ptr;

	nbr = "cbacbacba";
	bf = "abc";
	bt = "cba";
	ptr = ft_convert_base(nbr, bf, bt);
	printf("%s\n", ptr);
	free(ptr);
	return (0);
}
