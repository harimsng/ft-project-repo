#include <stdlib.h>

void	int_mergesort(int *arr, size_t len);
void	mergesort_split(int *arr, size_t left, size_t right, int *sorted);
void	mergesort_join(int *arr, size_t left, size_t right, int *sorted);

int	duplicate_detector(int *arr, size_t size)
{
	size_t	idx = 1;

	int_mergesort(arr, size);
	while (idx < size && arr[idx - 1] < arr[idx])
		++idx;
	return (idx != size);
}

void	int_mergesort(int *arr, size_t len)
{
	int		*sorted;
	size_t	idx;

	idx = 0;
	if (len < 2)
		return ;
	sorted = malloc(sizeof(int) * len);
	while (idx < len)
	{
		sorted[idx] = arr[idx];
		++idx;
	}
	mergesort_split(sorted, 0, len - 1, arr);
	free(sorted);
}

void	mergesort_split(int *sorted, size_t left, size_t right, int *arr)
{
	size_t	mid;

	if (right - left < 1)
		return ;
	mid = (left + right) / 2;
	mergesort_split(arr, left, mid, sorted);
	mergesort_split(arr, mid + 1, right, sorted);
	mergesort_join(sorted, left, right, arr);
}

void	mergesort_join(int *sorted, size_t left, size_t right, int *arr)
{
	size_t		idx;
	size_t		mid;
	size_t		up_bound;

	idx = left;
	up_bound = right + 1;
	mid = (left + right) / 2 + 1;
	right = mid;
	while (idx < up_bound)
	{
		if ((sorted[left] > sorted[right] && right < up_bound) || left == mid)
			arr[idx++] = sorted[right++];
		else
			arr[idx++] = sorted[left++];
	}
}
