#include <stdio.h>

#include <stdlib.h>

#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int	main(int argc, char **argv)
{
	struct s_stock_str	*ptr;

	if (argc == 1)
		return (0);
	ptr = ft_strs_to_tab(argc - 1, argv + 1);
	while (ptr->str)
	{
		printf("%d\n", ptr->size);
		printf("%s\n", ptr->str);
		(ptr->copy)[0] = '~';
		printf("%s\n", ptr->copy);
		free(ptr->copy);
		++ptr;
	}	
	printf("%p\n", ptr - argc + 1);
	free(ptr - argc + 1);
	printf("%p\n", ptr - argc + 1);
	return (0);
}
