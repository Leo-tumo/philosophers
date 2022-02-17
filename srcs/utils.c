/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: letumany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 22:53:39 by letumany          #+#    #+#             */
/*   Updated: 2022/02/15 23:30:26 by letumany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philos.h"

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
