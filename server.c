/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:12:05 by haeris            #+#    #+#             */
/*   Updated: 2022/07/31 10:10:10 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putnbr(unsigned int a)
{
	if (a > 9)
		ft_putnbr(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (0);
}

void	using_signal(int signal_control)
{
	static char	str;
	static int	count;

	if (signal_control == SIGUSR1)
		str = str | 1;
	if (++count == 8)
	{
		count = 0;
		if (!str)
			write(1, "\n", 1);
		write(1, &str, 1);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	ft_putnbr(getpid());
	write(1, "\n", 1);
	signal(SIGUSR1, using_signal);
	signal(SIGUSR2, using_signal);
	while (1)
	{
		pause();
	}
}
