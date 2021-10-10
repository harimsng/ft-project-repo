char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char	*ret;

	ret = dest;
	while (*src != 0 && n > 0)
	{
		*dest = *src;
		++dest;
		++src;
		--n;
	}
	if (n == 0)
		return (ret);
	while (n > 0)
	{
		*dest = 0;
		++dest;
		--n;
	}
	return (ret);
}
