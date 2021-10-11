unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	ret;

	idx = 0;
	while (idx < size && *dest != 0)
	{
		++dest;
		++idx;
	}
	ret = idx;
	while (idx < size - 1 && *src != 0)
	{
		*dest = *src;
		++ret;
		++idx;
		++dest;
		++src;
	}
	if (
	while (*src != 0)
	{
		++src;
		++ret;
	}
	return (ret);
}
