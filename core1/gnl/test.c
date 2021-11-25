#include <unistd.h>

int	main(void)
{
	char	buf;

	while (read(0, &buf, 1))
		continue ;
	return (0);
}
