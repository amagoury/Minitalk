/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:04:38 by amagoury          #+#    #+#             */
/*   Updated: 2024/03/06 17:02:06 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	signal_handel(int signum, siginfo_t *info, void *context)
{
	static char		c;
	static int		bits;

	(void)context;
	if (signum == SIGUSR1)
		c = c | (1 << bits);
	bits++;
	if (bits == 8)
	{
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		write(1, &c, 1);
		c = 0;
		bits = 0;
	}
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = signal_handel;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	ft_putnbr_fd (getpid(), 1);
	write (1, "\n", 1);
	while (1)
		usleep(300);
	return (0);
}
