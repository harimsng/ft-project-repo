#include <unistd.h>

void	ft_putstr(char *str);
void	initialize(char *arr);
void	increment(char *arr, int n);

void	ft_print_combn(int n)
{
	char	nums[9];
	char	backup[9];
	int		temp;

	initialize(nums);
	initialize(backup);
	ft_putstr(nums);
	if (n == 1)
	{
		ft_putstr("0123456789");
		return ;
	}
	while (nums[n - 2] < '9')
	{
		
	}
}

void	initialize(char *arr)
{
	int		idx;

	idx = 0;
	while (idx < 9)
	{
		arr[idx] = '0' + idx;
		idx++;
	}
}

void	ft_putnstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

void	increment(char *arr, int n)
{

