/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:59:42 by haeris            #+#    #+#             */
/*   Updated: 2022/07/17 12:24:11 by haeris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_putnbr(unsigned int a)
{
	if (a > 9)
		ft_putnbr(a / 10);
	write(1, &"0123456789"[a % 10], 1);
	return (0);
}

void	sig_handler(int signal_control, siginfo_t *sa, void *arg )
{
	static char	str;
	static int	count;

	if (arg)
		;
	if (signal_control == SIGUSR1)
		str = str | 1;
	if (++count == 8)
	{
		count = 0;
		if (!str)
		{
			write(1, "\n", 1);
			kill(sa->si_pid, SIGUSR1);
		}
		write(1, &str, 1);
		str = 0;
	}
	else
		str <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
