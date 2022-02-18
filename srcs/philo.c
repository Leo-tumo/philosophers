/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 22:55:17 by letumany          #+#    #+#             */
/*   Updated: 2022/02/18 21:32:54 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	*philo(void	*philo_tmp)
{
	t_philo	*philo;

	philo = (t_philo *)philo_tmp;
	philo->fed = get_time(0);
	while (1)
	{
		take_fork(philo);
		eating(philo);
		put_fork(philo);
		if (philo->must_eat != -1)
		{
			if (philo->must_eat != 0)
				--philo->must_eat;
		}
		sleeping_thinking(philo);
	}
	return (NULL);
}

static	int	check_for_death(t_data *data, int *eat_check, int *i)
{
	if (data->time_to_die < get_time(data->array_philo[*i].fed))
	{
		pthread_mutex_lock(&data->sms);
		printf("%zu %d died\n",
			get_time(data->array_philo[*i].begin_time), *i + 1);
		return (1);
	}
	if (data->array_philo[*i].must_eat == 0)
		--*eat_check;
	return (0);
}

static	void	*control(void *date_tmp)
{
	int		i;
	int		eat_check;
	t_data	*data;

	data = date_tmp;
	while (1)
	{
		i = -1;
		eat_check = data->count_philo;
		while (++i < data->count_philo)
		{
			if (check_for_death(data, &eat_check, &i))
				return (NULL);
		}
		if (eat_check == 0)
		{
			pthread_mutex_lock(&data->sms);
			return (NULL);
		}
	}
	return (NULL);
}

static	void	start_philo(t_data *data)
{
	int				i;
	pthread_t		god;

	i = -1;
	pthread_create(&god, NULL, control, (void *)data);
	while (++i < data->count_philo)
		pthread_create(&data->array_philo[i].thread,
			NULL, philo, (void *)&data->array_philo[i]);
	pthread_join(god, NULL);
	pthread_mutex_destroy(&data->sms);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 6 && argc != 5)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	else
	{
		if (init_data(argv, argc, &data))
			return (1);
	}
	start_philo(&data);
	return (0);
}
