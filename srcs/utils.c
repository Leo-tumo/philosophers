/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:36:36 by letumany          #+#    #+#             */
/*   Updated: 2022/02/18 20:57:14 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static	void	ft_atoi_init(int *i, long int *n, int *sign, const char *str)
{
	*i = 0;
	*n = 0;
	while (str[*i] == ' ' || str[*i] == '\t'
		|| str[*i] == '\n' || str[*i] == '\v'
		|| str[*i] == '\f' || str[*i] == '\r')
		++*i;
	if (str[*i] == '-')
		*sign = -1;
	else
		*sign = 1;
}

int	ft_atoi(const char *str)
{
	int			i;
	long int	n;
	int			sign;

	ft_atoi_init(&i, &n, &sign, str);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i] - '0');
		if ((n > 2147483647 && sign == 1)
			|| (n < -2147483647 && sign == -1))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		++i;
	}
	return (sign * n);
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
