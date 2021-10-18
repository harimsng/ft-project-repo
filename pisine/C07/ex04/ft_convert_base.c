#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (nbr == (void *)0 || base_from == (void *)0 || base_to == (void *)0)
		return ((void *)0);
