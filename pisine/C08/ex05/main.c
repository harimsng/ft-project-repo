#include "ft_stock_str.h"

#include <stdlib.h>

t_stock_str	*ft_strs_to_tab(int ac, char **av);
void		ft_show_tab(t_stock_str *par);

int	main(int argc, char **argv)
{
	t_stock_str		*ptr;
	int				idx;

	if (argc == 1)
		return (0);
	ptr = ft_strs_to_tab(argc - 1, argv + 1);	
	ft_show_tab(ptr);
	idx = 0;
	while ((ptr + idx)->str)
	{
		free((ptr + idx)->copy);
		++idx;
	}
	free(ptr);
	return (0);
}
