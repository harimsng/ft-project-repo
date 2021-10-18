#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int	main(void)
{
	int		arr[10];
	int		idx;

	idx = 0;
	while (idx < 10)
	{
		arr[idx] = (23984 + idx * 123) % 50;
		printf("%d ", arr[idx]);
		++idx;
	}
	printf("\n");
	ft_sort_int_tab(arr, 10);
	idx = 0;
	while (idx < 10)
	{
		printf("%d ", arr[idx]);
		++idx;
	}
	return (0);
}
