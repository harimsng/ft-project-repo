int	ft_strcheck(unsigned char *str, int size)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != '\n' && len < size)
		++len;
	if ((str[len] && str[len] != '\n') || len != size)
		return (1);
	return (0);
}
