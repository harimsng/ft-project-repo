#include <unistd.h>

void	my_print(char *l1, char *l2, char *r1, char *r2);

void	last_part(void);

int	main(void)
{
	char	left[2];
	char	right[2];

	left[0] = '0';
	left[1] = '0';
	right[0] = '0';
	right[1] = '1';
	while (left[0] != '9' && left[1] != '8')
	{
		if (left[0] != right[0] || left[1] != right[1])
			my_print(left, left + 1, right, right + 1);
		++right[1];
		if (right[1] > '9')
		{
			++right[0];
			right[1] = '0';
		}
		if (right[0] > '9')
		{
			++left[1];
			right[0] = left[0];
			right[1] = left[1] + 1;
		}
		if (left[1] > '9')
		{
			++left[0];
			left[1] = '0';
			right[0] = left[0];
			right[1] = left[1] + 1;
		}
	}
	write(1, "9", 1);
	return (0);
}

void	my_print(char *l1, char *l2, char *r1, char *r2)
{
	write(1, l1, 1);
	write(1, l2, 1);
	write(1, " ", 1);
	write(1, r1, 1);
	write(1, r2, 1);
	write(1, ",", 1);
	write(1, " ", 1);
}

void	last_part(void)
{
	write(1, "9", 1);
	write(1, "8", 1);
	write(1, " ", 1);
	write(1, "9", 1);
	write(1, "9", 1);
}
