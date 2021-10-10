int	ft_str_is_lowercase(char *str)
{
	while (1)
	{
		if (*str == 0)
			return (1);
		else if (*str < 'a' || *str > 'z')
			return (0);
		++str;
	}
	return (1);
}
