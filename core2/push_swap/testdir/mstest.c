#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "ft_debug.h"

void	mergesort_list(t_list *list);

int	main(void)
{
	t_list	list = {NULL, 0};
	t_node	*node;

	push_back(&list, 126);
	*list.head = (t_node){126, NULL};
	node = list.head;
	for (int i = 0; i < 30; ++i)
	{
		push_back(&list, (node->item * 5 + 76) % 127);
		node = node->next;
	}
	printf("before sort\n");
	print_list(&list);
	mergesort_list(&list);
	printf("\nafter sort\n");
	print_list(&list);
	return (0);
}
