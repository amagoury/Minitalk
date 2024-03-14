/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:57:42 by amagoury          #+#    #+#             */
/*   Updated: 2024/03/03 20:20:50 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	hand_signl(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Message received!\n", STDOUT_FILENO);
}

void	sender_pid(int pid, char *c)
{
	int		i;
	int		j;

	i = 0;
	while (c[i] != '\0')
	{
		j = 0;
		while (j <= 7)
		{
			if ((c[i] & (1 << j)) != 0)
				kill (pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep (300);
			j++;
		}
		i++;
	}
	while (j != -1)
	{
		kill(pid, SIGUSR2);
		usleep(300);
		j--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		return ((void)write(1, "There is Error\n", 16), 1);
		return (1);
	}
	signal(SIGUSR1, hand_signl);
	pid = ft_atoi(av[1]);
	sender_pid(pid, av[2]);
	usleep(300);
	return (0);
}
