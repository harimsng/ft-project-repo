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
		2637, 2663, 3105, 2634, 2660, 2636, 2662, 3078, 80142, 68650, 69326
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
