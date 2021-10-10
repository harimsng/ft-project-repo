char	*ft_strupcase(char *str)
{
	int		diff;
	char	*ret;

	ret = str;
	diff = 'a' - 'A';
	while (*str != 0)
	{
		if (*str >= 'a' && *str <= 'z')
			*str = *str - diff;
		++str;
	}
	return ret;
}
