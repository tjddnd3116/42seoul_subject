#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>

struct s_info;

typedef struct s_philo
{
	pthread_t	thread;
	int	id;
	int r_fork;
	int l_fork;
	struct s_info *info;
}	t_philo;

typedef struct s_info
{
	t_philo	*philo;
	pthread_mutex_t *forks;
	struct timeval start_time;
	int	num_philo;
	int time_die;
	int	time_eat;
	int	time_sleep;
	int	num_eat;
	int	philo_die;
}	t_info;

//util.c
void	init_info(t_info *info, int argc, char **argv);
int		ft_atoi(const char *str);
//dinning_philo.c
void	dinning_philo(t_info *info);
//error.c
void	error();
//eat_think_sleep.c
void	eating(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
#endif
