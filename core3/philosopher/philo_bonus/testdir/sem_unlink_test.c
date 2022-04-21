#include <semaphore.h>
#include <stdio.h>
#include <sys/errno.h>
#include <string.h>

int	main(void)
{
	static const char	*name = "abc";
	sem_t	*my_sem = sem_open(name, O_CREAT, 0666, 1);

	perror(NULL);
	sem_wait(my_sem);
	sem_post(my_sem);
	printf("unlinking semaphore\n");
	sem_close((void *)1234);
	printf("errno = %d, EINVAL = %d\n", errno, EINVAL);
	printf("%s\n", strerror(errno));
	sem_unlink("abcd");
	printf("errno = %d, ENOENT = %d\n", errno, ENOENT);
	printf("%s\n", strerror(errno));
	sem_unlink(name);
	printf("errno = %d, ENOENT = %d\n", errno, ENOENT);
	printf("%s\n", strerror(errno));
	printf("unlinked\n");
	printf("SEM_FAILED = %p\n", SEM_FAILED);
	return (0);
}
