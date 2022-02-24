#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	ft_atoi(const char *s);

static char		*test[] =
{
	"   +12345678901234",
	"\n  -12345678",
	"\t 1234",
	"4321",
	"  +1234567890123",
	"\t  -123456789",
	" \n1234",
	"-4321"
};

int	main(void)
{
	clock_t	start, end;
	double	time1, time2;
	int		temp1, temp2;

	start = clock();
	for (int i = 0; i < 10000000; ++i)
	{
		temp1 =	ft_atoi(test[i & 7]); 
		(void)temp1;
	}
	end = clock();
	time1 = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();
	for (int i = 0; i < 10000000; ++i)
	{
		temp2 = atoi(test[i & 7]);
		(void)temp2;
	}
	end = clock();
	time2 = (double)(end - start) / CLOCKS_PER_SEC;

	printf("ft_atoi : %f\natoi : %f\n", time1, time2);
	return (0);
}
