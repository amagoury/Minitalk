/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:04:38 by amagoury          #+#    #+#             */
/*   Updated: 2024/03/06 17:02:14 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handel(int signum)
{
	static char		c;
	static int		bits;

	if (signum == SIGUSR1)
		c = c |(1 << bits);
	bits++;
	if (bits == 8)
	{
		write (1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int	main(void)
{
	signal (SIGUSR1, &signal_handel);
	signal (SIGUSR2, &signal_handel);
	ft_putnbr_fd (getpid(), 1);
	write (1, "\n", 1);
	while (1)
		usleep(300);
	return (0);
}
