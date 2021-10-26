int	ft_stoi(char *str)
{
	int		ret;

	ret = 0;
	while (*str)
		ret = ret * 10 + *str++ - '0';
	return (ret);
}
