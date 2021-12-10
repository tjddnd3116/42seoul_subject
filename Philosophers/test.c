#include <stdio.h>
#include <pthread.h>

void	*eat(void *arg)
{
	//printf("here");
	pthread_mutex_t *forks = (pthread_mutex_t *)arg;
	pthread_mutex_lock(forks);
	pthread_mutex_lock(forks);
	printf("eating\n");
	pthread_mutex_unlock(forks);
	pthread_mutex_unlock(forks);
	return (0);
}

int main(void)
{
	pthread_t philo1;
	pthread_t philo2;
	pthread_mutex_t forks;

	pthread_mutex_init(&forks, NULL);
	pthread_mutex_init(&forks, NULL);
	pthread_create(&philo1, NULL, eat, (void *)&forks);
	pthread_create(&philo2, NULL, eat, (void *)&forks);
	pthread_join
}
