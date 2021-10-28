void	print_error(char *filename)
{
	ft_puterr(prog_name);
	ft_puterr(filename);
	ft_puterr(": ");
	ft_puterr(strerr(errno));
	ft_puterr("\n");
}
