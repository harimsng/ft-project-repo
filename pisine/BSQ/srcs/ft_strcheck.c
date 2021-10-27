int	ft_strcheck(char *str, unsigned int size)
{
	unsigned int	len;

	len = 0;
	while (str[len] && str[len] != '\n' && len < size)
		++len;
	if ((str[len] && str[len] != '\n') || len != size)
		return (1);
	return (0);
}
