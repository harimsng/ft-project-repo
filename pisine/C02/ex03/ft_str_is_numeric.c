int	ft_str_is_numeric(char *str)
{
	while (1)
	{
		if (*str == 0)
			return (1);
		else if (*str < '0' || *str > '9')
			return (0);
		++str;
	}
	return (1);
}
