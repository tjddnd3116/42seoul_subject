/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soum <soum@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 14:08:50 by soum              #+#    #+#             */
/*   Updated: 2022/01/05 19:41:05 by soum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				r_fork;
	int				l_fork;
	struct s_info	*info;
	long long		last_eat;
	int				eat_count;
	long long		now_time;
	int				full;
}	t_philo;

typedef struct s_info
{
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	all_eat_m;
	long long		start_time;
	int				*use_forks;
	int				num_philo;
	int				philo_idx;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				philo_die;
	long long		end_time;
	int				all_eat;
	int				all_eat_cnt;
}	t_info;

//util.c
int			ft_atoi(const char *str);
long long	now_time_ms(void);
int			ft_strlen(char *str);
int			arg_check(int argc, char **argv);
//init_info.c
int			init_info(t_info *info, int argc, char **argv);
int			init_mutex(t_info *info);
int			init_philo(t_info *info);
//dinning_philo.c
int			create_philo(t_info *info);
void		dinning_philo(t_info *info);
//error.c
int			all_free_exit(t_info *info, char *str);
//eat_think_sleep.c
int			is_dead(t_philo *philo);
void		hold_fork(t_philo *philo);
void		eating(t_philo *philo);
void		thinking(t_philo *philo);
void		sleeping(t_philo *philo);
//message.c
void		print_message(t_philo *philo, char *str);
//thread.c
void		join_thread(t_info *info);
void		main_thread(t_info *info);
#endif
