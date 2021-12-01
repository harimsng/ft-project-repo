#include "../libft.h"

#define LST_SIZE (10)

void	ft_lstprint(t_list *lst, void (*f)(void *));
void	int_print(void *addr);
void	int_assign(int n, void *addr);
void	int_del(void *addr);

int	main(void)
{
	t_list		*head;
	t_list		*node;
	t_list		**temp;
	int			idx;

	idx = 0;
	head = ft_lstnew(malloc(sizeof(int)));
	int_assign(-1, head->content);
	node = head;
	while (idx < LST_SIZE)
	{
		ft_lstadd_back(&head, ft_lstnew(malloc(sizeof(int))));
		node = node->next;
		int_assign(idx, node->content);
		++idx;
	}
	ft_lstprint(head, int_print);
	ft_putstr_fd("\n", 1);
	idx = 0;
	temp = &(head->next);
	while (idx < LST_SIZE)
	{
		ft_lstadd_front(&head, ft_lstnew(malloc(sizeof(int))));
		int_assign(idx, head->content);
		++idx;
	}
	ft_lstprint(head, int_print);
	ft_putstr_fd("\n", 1);
	ft_lstclear(temp, int_del);
	ft_lstprint(head, int_print);
	ft_lstclear(&head, int_del);
	return (0);
}

void	ft_lstprint(t_list *lst, void (*f)(void *))
{
	size_t		idx;

	idx = 0;
	while (lst)
	{
		ft_putnbr_fd(idx, 1);
		ft_putstr_fd("th element's content: ", 1);
		f(lst->content);
		ft_putchar_fd('\n', 1);
		lst = lst->next;
		++idx;
	}
}

void	int_print(void *addr)
{
	if (!addr)
		return ;
	ft_putnbr_fd(*(int *)addr, 1);
}

void	int_assign(int n, void *addr)
{
	int		*ptr;

	ptr = addr;
	*ptr = n;
}

void	int_del(void *addr)
{
	free(addr);
}
