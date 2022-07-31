/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:12:22 by haeris            #+#    #+#             */
/*   Updated: 2022/07/17 09:39:48 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_send(int pid, char *str)
{
	int		count;
	char	c;

	count = 8;
	while (*str)
	{
		count = 8;
		c = *(str++);
		while (count--)
		{
			if (c >> count & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
	count = 8;
	while (count--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int count, char **str)
{
	if (count < 3)
	{
		write(1, "I guess, something is missing :)", 32);
		return (1);
	}
	ft_send(ft_atoi(str[1]), str[2]);
}
