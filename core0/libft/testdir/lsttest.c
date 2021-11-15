#include "../libft.h"

int	main(void)
{
	t_list	*head;
	int		num;

	num = 0;
	head = ft_lstnew(&num);
	free(head);
	return (0);
}
