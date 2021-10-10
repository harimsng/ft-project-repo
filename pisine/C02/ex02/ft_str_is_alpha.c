int	ft_str_is_alpha(char *str)
{
	while (1)
	{
		if (*str == 0)
			return (1);
		else if (*str < 'A' || (*str > 'Z' && *str < 'a' ) || *str > 'z')
			return (0);
		++str;
	}
	return (1);
}
