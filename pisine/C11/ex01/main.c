#include <stdio.h>
#include <stdlib.h>

#define LEN 20

int	*ft_map(int *tab, int length, int (*f)(int));
int	add_one(int num);

int	main(void)
{
	int		arr[LEN];
	int		idx;
	int		*ptr;

	idx = 0;
	while (idx < LEN)
	{
		arr[idx] = idx;
		printf("%d ", arr[idx]);
		++idx;
	}
	printf("\n");
	ptr = ft_map(arr, LEN, add_one);
	idx = 0;
	while (idx < LEN)
		printf("%d ", ptr[idx++]);
	printf("\n");
	free(ptr);
	return (0);
}

int	add_one(int num)
{
	return (num + 1);
}
