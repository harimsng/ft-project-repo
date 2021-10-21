#include "ft_stock_str.h"

#include <stdio.h>

#include <stdlib.h>

t_stock_str	*ft_strs_to_tab(int ac, char **av);
void		ft_show_tab(t_stock_str *par);
void		*ft_print_memory(void *addr, unsigned int size);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	t_stock_str		*ptr = ft_strs_to_tab(argc - 1, argv + 1);	
	int				idx;

//	ft_print_memory(ptr, 161);
//	ft_print_memory(ptr->str, 161);
	ft_show_tab(ptr);
	printf("free starts\n");
	printf("ptr = %p\n", ptr);
	idx = 0;
	while ((ptr + idx)->str)
	{
		printf("%p\n", (ptr + idx)->copy);
		free((ptr + idx)->copy);
		++idx;
	}
	printf("null %p\n", (ptr + idx)->str);
	printf("ptr = %p\n", ptr);
	free(ptr);
	return (0);
}
