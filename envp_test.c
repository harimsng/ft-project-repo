#include <stdio.h>

void	*ft_print_memory(void *addr, size_t len);

int	main(int argc, char *argv[], char *envp[])
{
	(void)argc;
	printf("argv address: %p\n", argv);
	printf("argv[0] address: %p\n", argv[0]);
	ft_print_memory(argv[0], 256);

	printf("envp address: %p\n", envp);
	printf("envp[0] address: %p\n", envp[0]);
	ft_print_memory(envp[0], 256);
}
