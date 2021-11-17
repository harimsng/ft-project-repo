#include "../includes/ft.h"
#include "../includes/ft_dict.h"

// return (1)	: Dict Error
// ref_dict 	: malloced t_dict array of size 41
// if dict_size is smaller than 41, return Dict Error before this function.
int	remove_dict(t_dict *ref_dict, t_dict *dict_arr, int dict_size)
{
	int			idx;
	int			jdx;
	int			kdx;

	idx = 0;
	jdx = 40;
	kdx = 0;
	while (idx < dict_size)
	{
		while (dict_arr[idx].key < g_entries[jdx].key)
		{
			free(dict_arr[idx].value);
			++idx;
		}
		if (dict_arr[idx].key != dict_arr[idx].key)
			return (1);
		ref_dict[kdx].key = dict_arr[idx].key;
		ref_dict[kdx++].value = dict_arr[idx].value;
		free(dict_arr[idx].value);
		++idx;
		--jdx;
	}
	free(dict_arr);
	return (0);
}
