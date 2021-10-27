void	ft_strccpy(unsigned char *dest, unsigned char *src, int width)
{
	int		idx;

	idx = 0;
	while (idx < width)
	{
		dest[idx] = src[idx];
		++idx;
	}
}
