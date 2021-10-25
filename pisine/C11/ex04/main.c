#include <stdio.h>

#define	LEN 10

int	ft_is_sort(int *tab, int length, int (*f)(int, int));
int	ft_intcmp(int a, int b);

int	main(void)
{
	int		arr[LEN];
	int		idx;

	idx = 0;
	while (idx < LEN)
	{
		arr[idx] = idx;
		++idx;
	}
	idx = 0;
	arr[5] = 0;
	while (idx < LEN)
		printf("%d ", arr[idx++]);
	printf("\nis it sorted? (1 or 0) : %d\n", ft_is_sort(arr, LEN, ft_intcmp));
	return (0);

}

int	ft_intcmp(int a, int b)
{
	return (a - b);
}
