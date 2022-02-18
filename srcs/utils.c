/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:36:36 by letumany          #+#    #+#             */
/*   Updated: 2022/02/18 23:14:21 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ft_error(char *s)
{
	printf("Error\n%s", s);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	if (str[0] == '0')
		ft_error("Wrong arguments");
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	if ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
		ft_error("Wrong arguments");
	return (num);
}

static	void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	if (n == 0)
		return ;
	tmp = s;
	while (n-- != 0)
		*tmp++ = '\0';
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}
