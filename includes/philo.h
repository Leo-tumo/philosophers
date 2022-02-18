/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 20:57:54 by letumany          #+#    #+#             */
/*   Updated: 2022/02/18 22:14:15 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				index;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	pthread_mutex_t	*sms;
	pthread_t		thread;
	ssize_t			time_to_die;
	ssize_t			time_to_eat;
	ssize_t			time_to_sleep;
	ssize_t			must_eat;
	ssize_t			begin_time;
	ssize_t			fed;
}					t_philo;

typedef struct s_data
{
	int				count_philo;
	ssize_t			begin_time;
	ssize_t			time_to_die;
	ssize_t			time_to_eat;
	ssize_t			time_to_sleep;
	ssize_t			must_eat;
	pthread_mutex_t	sms;
	t_philo			*array_philo;
}				t_data;

int			init_data(char **argv, int argc, t_data *data);
void		*ft_calloc(size_t count, size_t size);
void		sleeping_thinking(t_philo *philo);
ssize_t		get_time(ssize_t begin_time);
void		take_fork(t_philo *philo);
void		put_fork(t_philo *philo);
int			ft_atoi(const char *str);
void		m_sleep(ssize_t time);
void		eating(t_philo *philo);

#endif
