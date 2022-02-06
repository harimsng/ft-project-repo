#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void	mergesort_list(t_node **head);

int	main(void)
{
	t_list	list = {NULL, 0};

	for (int i = 0, prev = 2; i < 20; ++i)
	{
		push_front(&list, (prev * 73 + 76) % 127);
		prev = list.head->num;
	}
	print_list(list.head);
	mergesort_list(&list.head);
	print_list(list.head);
	return (0);
}
