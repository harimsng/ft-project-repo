#include <unistd.h>
#include <stdio.h>

void    *ft_print_memory(void *addr, size_t len);

int main(int argc, char *argv[], char *envp[])
{
    char    str[5] = "1234";
    int     i = 0;

	printf("argc addr: %p: %d\n", &argc, argc);
    printf("main function arguments\naddr: %p\n", argv);
    while (argv[i])
    {
		printf("%d) %p: %s\n", i, argv[i], argv[i]);
		++i;
    }

	i = 0;
    printf("environtal variables\naddr: %p\n", envp);
    while (envp[i])
    {
		printf("%d) %p: %s\n", i, envp[i], envp[i]);
		++i;
    }

	printf("memory around local variables\n");
    ft_print_memory(str, 256);
	printf("memory around argv\n");
	ft_print_memory(*argv, 1024);
	printf("memory around envp\n");
	ft_print_memory(*envp, 4096);

	return (0);
}
