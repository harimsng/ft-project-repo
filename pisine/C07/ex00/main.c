#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	*ft_print_memory(void *addr, unsigned int size);
char	*ft_strdup(char *str);

int main(void)
{
	char	*str;
	char	*ptr;
	char	*ptr2;
	char	arr[16] = {'s', 't', 'a', 'c', 'k'};

	ft_print_memory((void *)arr, 32);
	printf("\n");

	str = "1234567890 read only or heap";
	ft_print_memory((void *)str, 32);
	ptr = strdup(str);
	ptr2 = ft_strdup(str);
	printf("\n%s\n", ptr);
	printf("%s\n", ptr2);
	ft_print_memory((void *)ptr, 64);
	printf("\n");
	ft_print_memory((void *)ptr2, 32);
	free(ptr);
	free(ptr2);
	return (0);
}
