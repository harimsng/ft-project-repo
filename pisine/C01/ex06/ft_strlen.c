int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (*str != '\0' && len != 2147483647)
	{
		++len;
		++str;
	}
	return (len);
}
