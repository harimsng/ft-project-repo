#include <stdio.h>

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2);
void	ft_putstr(char *str);

// be careful about minidx
// if argv[1] is smallest, minidx will not be reassigned.
int	main(int argc, char **argv)
{
	char	*minptr;
	int		minidx;
	int		idx;
	int		jdx;

	idx = 1;
	while (idx < argc)
	{
		jdx = 1;
		minptr = NULL;
		while (jdx < argc)
		{
			if (ft_strcmp(argv[jdx], minptr) < 0)
			{
				minptr = argv[jdx];
				minidx = jdx;
			}
			++jdx;
		}
		ft_putstr(minptr);
		write(1, "\n", 1);
		argv[minidx] = NULL;
		++idx;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	while (*str != 0)
	{
		write(1, str, 1);
		++str;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	if (s2 == NULL)
		return (-1);
	if (s1 == NULL)
		return (0);
	while (*s1 == *s2 && *s1 != 0 && *s2 != 0)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
