#include <stdlib.h>
#include <stdio.h>

#define COEF (26)
#define ELEMENTS (11)

int		duplicate_detector(int *arr, size_t size);
void	modulus_table(int divider, int *arr, int *out, size_t size);
void	print_table(int *arr, size_t size);

int	main(void)
{
	int		table[ELEMENTS] =
	{
		2595, 2621, 1971, 2592, 2618, 2594, 67516, 2620, 68192, 1944, 50616
	};
	int		result_table[ELEMENTS] = {0, };
	int		divider = ELEMENTS;
	
	modulus_table(divider, table, result_table, ELEMENTS);
	while (duplicate_detector(result_table, ELEMENTS))
	{
		++divider;
		modulus_table(divider, table, result_table, ELEMENTS);
	}
	printf("divider = %d\n", divider);
	print_table(result_table, ELEMENTS);
}

void	modulus_table(int divider, int *arr, int *out, size_t size)
{
	for (size_t i = 0; i < size; ++i)
		out[i] = arr[i] % divider;
}

void	print_table(int *arr, size_t size)
{
	for (size_t	i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
