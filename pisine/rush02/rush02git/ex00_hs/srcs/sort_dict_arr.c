#include "../includes/ft.h"
#include "../includes/ft_dict.h"

// line 19: adjusts direction of inequality symbol
void sort_dict(t_dict *dict_arr, int dict_size)
{
	int		idx;
	int		jdx;

	idx = 0;
	while (idx < dict_size - 1)
	{
		jdx = idx + 1;
		while (jdx < dict_sizee)
		{
			if (dict_arr[idx].key < dict_arr[jdx].key)
			{
				ft_swap(dict_arr[idx].key, dict_arr[jdx].key);
				ptr_swap(dict_arr[idx].value, dict_arr[jdx].value);
			}
			++jdx;
		}
		++idx;
	}
}
