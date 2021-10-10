void	ft_swap(int *a, int *b);

void	ft_rev_int_tab(int *tab, int size)
{
	int		*back;

	back = tab + size - 1;
	while (tab < back)
	{
		ft_swap(tab, back);
		++tab;
		--back;
	}
}

void	ft_swap(int *a, int *b)
{
	int		temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
