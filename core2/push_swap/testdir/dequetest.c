#include <stdio.h>
#include "ft_deque.h"

int	main(void)
{
	t_deque		deque = {NULL, NULL, NULL, 0};
	t_deque		deque2 = {NULL, NULL, NULL, 0};

	for (int i = 0, num = 126; i < 30; ++i)
	{
		push_back(&deque, num);
		num = (num * 5 + 76) % 127;
	}
	push_back(&deque2, 12345);

	printf("\nbefore rotation\n");
	print_deque_forward(&deque);
	inst_rotation(&deque);
	inst_rotation(&deque);
	inst_rotation(&deque);
	printf("\nafter rotation\n");
	print_deque_forward(&deque);
	inst_revrot(&deque);
	inst_revrot(&deque);
	inst_revrot(&deque);
	printf("\nafter reverse rotation\n");
	print_deque_forward(&deque);
	inst_swap(&deque);
	printf("\nafter swap\n");
	print_deque_forward(&deque);

	inst_push(&deque2, &deque);
	inst_push(&deque2, &deque);
	inst_push(&deque2, &deque);
	inst_push(&deque2, &deque);
	inst_push(&deque2, &deque);
	inst_push(&deque2, &deque);
	inst_push(&deque2, &deque);
	printf("\nafter push\n");
	print_deque_forward(&deque);
	printf("\ndeque2:\n");
	print_deque_forward(&deque2);
	return (0);
}
