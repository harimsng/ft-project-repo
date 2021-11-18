#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	main(void)
{
	char	arr[100];

	memset(arr, '1', 100);
	read(0, arr, 100);
	printf("%s\n", arr);
	return (0);
}
