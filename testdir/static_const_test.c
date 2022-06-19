#include <stdio.h>

void	change_num(int *num);

// static only : possible
// with const : bus error
static const int	num = 42;

int	main(void)
{
	printf("%d\n", num);
	change_num((int *)&num);
	printf("%d\n", num);
	return (0);
}
