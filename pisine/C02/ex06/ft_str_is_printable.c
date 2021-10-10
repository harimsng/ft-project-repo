int	ft_str_is_printable(char *str)
{
	while (1)
	{
		if (*str == 0)
			return (1);
		else if (*str < 32)
			return (0);
		++str;
	}
	return (1);
}
