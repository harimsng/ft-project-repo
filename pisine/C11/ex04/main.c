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
	arr[0] = 7;
	arr[1] = 7;
	arr[2] = 6;
	arr[3] = 6;
	arr[4] = 5;
	arr[5] = 5;
	arr[6] = 6;
	arr[7] = 2;
	arr[8] = 1;
	arr[9] = 0;
	idx = 0;
	while (idx < LEN)
		printf("%d ", arr[idx++]);
	printf("\nis it sorted? (1 or 0) : %d\n", ft_is_sort(arr, LEN, ft_intcmp));

	idx = 0;
	while (idx < LEN)
	{
		arr[idx] = LEN - idx;
		++idx;
	}
	arr[5] = -2;
	idx = 0;
	while (idx < LEN)
		printf("%d ", arr[idx++]);
	printf("\nis it sorted? (1 or 0) : %d\n", ft_is_sort(arr, LEN, ft_intcmp));
	return (0);

}

int	ft_intcmp(int a, int b)
{
	return (a - b);
}
