/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:25:49 by letumany          #+#    #+#             */
/*   Updated: 2022/02/18 22:14:45 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	take_fork_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	pthread_mutex_lock(philo->sms);
	printf("%zu %d has taken a fork\n",
		get_time(philo->begin_time), philo->index + 1);
	pthread_mutex_unlock(philo->sms);
	pthread_mutex_lock(philo->rfork);
	pthread_mutex_lock(philo->sms);
	printf("%zu %d has taken a fork\n",
		get_time(philo->begin_time), philo->index + 1);
	pthread_mutex_unlock(philo->sms);
}

void	take_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(philo->rfork);
		pthread_mutex_lock(philo->sms);
		printf("%zu %d has taken a fork\n",
			get_time(philo->begin_time), philo->index + 1);
		pthread_mutex_unlock(philo->sms);
		pthread_mutex_lock(philo->lfork);
		pthread_mutex_lock(philo->sms);
		printf("%zu %d has taken a fork\n",
			get_time(philo->begin_time), philo->index + 1);
		pthread_mutex_unlock(philo->sms);
	}
	else
		take_fork_odd(philo);
}

void	put_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(philo->rfork);
		pthread_mutex_unlock(philo->lfork);
	}
	else
	{
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
	}
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->sms);
	printf("%zu %d is eating\n",
		get_time(philo->begin_time), philo->index + 1);
	philo->fed = get_time(0);
	pthread_mutex_unlock(philo->sms);
	m_sleep(philo->time_to_eat);
}

void	sleeping_thinking(t_philo *philo)
{
	pthread_mutex_lock(philo->sms);
	printf("%zu %d is sleeping\n",
		get_time(philo->begin_time), philo->index + 1);
	pthread_mutex_unlock(philo->sms);
	m_sleep(philo->time_to_sleep);
	pthread_mutex_lock(philo->sms);
	printf("%zu %d is thinking\n",
		get_time(philo->begin_time), philo->index + 1);
	pthread_mutex_unlock(philo->sms);
}
