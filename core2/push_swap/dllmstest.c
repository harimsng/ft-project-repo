#include <stdio.h>
#include "doublyll.h"

int	main(void)
{
	t_doublyll	list = {NULL, NULL, NULL, 0};

	push_front(&list, 126);
	list.cur = list.head;
	for (int i = 0; i < 50; ++i)
	{
		push_back(&list, (list.cur->item * 75 + 76) % 127);
		list.cur = list.cur->next;
	}
	print_list_foward(&list);
	mergesort_doublyll(&list);
	print_list_foward(&list);
	return (0);
}
