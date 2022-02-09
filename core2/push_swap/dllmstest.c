#include <stdio.h>
#include "dlinkedlist.h"

int	main(void)
{
	t_dlist list = {NULL, NULL, NULL, 0};

	push_front(&list, 126);
	list.cur = list.head;
	for (int i = 0; i < 30; ++i)
	{
		push_back(&list, (list.cur->item * 5 + 76) % 127);
		list.cur = list.cur->next;
	}
	printf("before sort\n");
	print_dlist_foward(&list);
	mergesort_dlist(&list);
	printf("\nafter sort\n");
	print_dlist_foward(&list);
	printf("\nbackward\n");
	print_dlist_backward(&list);
	printf("\npop_back\n");
	while (list.size)
		printf("%d ", pop_back(&list));
	return (0);
}
