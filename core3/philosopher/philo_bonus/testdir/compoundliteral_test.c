#include <stdio.h>

typedef struct s_struct
{
	int		i;
	double	d;
}			t_struct;

void	*func(void *arg)
{
	t_struct	*var = arg;

	printf("%d %lf\n", var->i, var->d);
	return (NULL);
}

int	main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		func(&(t_struct){i, 0.5 * i});
	}
	return (0);
}
