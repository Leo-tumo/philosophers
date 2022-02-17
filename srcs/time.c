/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 10:32:46 by letumany          #+#    #+#             */
/*   Updated: 2022/02/17 10:33:56 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

void	my_usleep(ssize_t time)
{
	struct timeval	t1;
	ssize_t			timing;

	gettimeofday(&t1, NULL);
	timing = t1.tv_sec * 1000 + t1.tv_usec / 1000;
	while (time > (t1.tv_sec * 1000 + t1.tv_usec / 1000) - timing)
	{
		gettimeofday(&t1, NULL);
		usleep(100);
	}
}

ssize_t	get_time(ssize_t begin_time)
{
	struct timeval	t1;

	gettimeofday(&t1, NULL);
	return ((t1.tv_sec * 1000 + t1.tv_usec / 1000) - begin_time);
}
