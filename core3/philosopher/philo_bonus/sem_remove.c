#include <semaphore.h>
#include <stdio.h>

static const char	*g_sem_forks = "philo_sem_forks";
static const char	*g_sem_speak = "philo_sem_speak";
static const char	*g_sem_access = "philo_sem_access";
static const char	*g_sem_wait = "philo_sem_monitor";

int	main(void)
{
	if (sem_unlink(g_sem_forks) != 0)
		printf("%s close failed\n", g_sem_forks);
	if (sem_unlink(g_sem_speak) != 0)
		printf("%s close failed\n", g_sem_speak);
	if (sem_unlink(g_sem_access) != 0)
		printf("%s close failed\n", g_sem_access);
	if (sem_unlink(g_sem_wait) != 0)
		printf("%s close failed\n", g_sem_wait);
	return (0);	
}
