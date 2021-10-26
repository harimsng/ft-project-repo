unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int		ret;

	ret = 0;
	while (src[ret])
		++ret;
	if (!size || !dest)
		return (ret);
	while (size - 1)
	{
		*dest = *src;
		++src;
		++dest;
		--size;
	}
	*dest = 0;
	return (ret);
}
