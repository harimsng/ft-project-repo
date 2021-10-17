void	ft_print_memory(void *addr, unsigned int n);

#define LEN	155

int	main(void)
{
	char	*ptr;
	char	str[LEN];
	int		idx;
	
	idx = 0;
	while (idx < LEN)
	{
		str[idx] = idx;
		++idx;
	}
	ptr = str;
	ft_print_memory(ptr, LEN);
	return (0);
}
/*
11110000
16 32 64 128
48
112
240
01111111 = 127
10000000 = 127 - 255 = -128
11111000 = 7 - 255 = -248
*/
