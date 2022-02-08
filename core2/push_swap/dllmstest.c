#include <stdio.h>
#include "doublyll.h"

int	main(void)
{
	t_doublyll	list = {NULL, NULL, NULL, 0};

	push_front(&list, 126);
	list.cur = list.head;
	for (int i = 0; i < 30; ++i)
	{
		push_back(&list, (list.cur->item * 5 + 76) % 127);
		list.cur = list.cur->next;
	}
	printf("before sort\n");
	print_list_foward(&list);
	mergesort_doublyll(&list);
	printf("\nafter sort\n");
	print_list_foward(&list);
	printf("\nbackward\n");
	print_list_backward(&list);
	return (0);
}
