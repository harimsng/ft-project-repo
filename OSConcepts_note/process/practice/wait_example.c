#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int	main(void)
{
	int		n;
	int		id;

	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(NULL);
	for (int i = 0; i < 5; ++i, ++n)
	{
		printf("%d ", n);
		fflush(stdout);
		// flust buffer without using newline in format string.
	}
	if (id != 0)
		printf("\n");
	return (0);
}
