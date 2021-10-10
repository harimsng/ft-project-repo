int	ft_str_is_uppercase(char *str)
{
	while (1)
	{
		if (*str == 0)
			return (1);
		else if (*str < 'A' || *str > 'Z')
			return (0);
		++str;
	}
	return (1);
}
