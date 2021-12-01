#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int	main(void)
{
	printf("%d %d\n", atoi(" \t\n\r\f\v+2147483647"), ft_atoi(" \t\n\r\f\v+2147483647"));
	printf("%d %d\n", atoi(" \t\n\r\f\v-2147483648"), ft_atoi(" \t\n\r\f\v-2147483648"));
	printf("%d %d\n", atoi(" \t\n\r\f\v+1"), ft_atoi(" \t\n\r\f\v+1"));
	printf("%d %d\n", atoi(" \t\n\r\f\v-"), ft_atoi(" \t\n\r\f\v-"));
}
