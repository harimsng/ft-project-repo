char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	len;
	char			*ret;

	ret = dest;
	while (*dest != 0)
		++dest;
	len = 0;
	while (len < nb && *src != 0)
	{
		*dest = *src;
		++dest;
		++src;
		++len;
	}
	return (ret);
}
