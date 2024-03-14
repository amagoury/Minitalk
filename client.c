/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amagoury <amagoury@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:57:42 by amagoury          #+#    #+#             */
/*   Updated: 2024/03/06 17:02:31 by amagoury         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		write(1, "There is Error\n", 16);
		return (1);
	}
	pid = ft_atoi(av[1]);
	sender_pid(pid, av[2]);
	return (0);
}
