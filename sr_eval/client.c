/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inaranjo <inaranjo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:19:55 by inaranjo          #+#    #+#             */
/*   Updated: 2023/03/10 14:14:35 by inaranjo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm_msg(int sign)
{
	if (sign == SIGUSR2)
		ft_printf ("message recieved\n");
}

void	emetteur(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep (500);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i] != '\0')
		{
			emetteur(pid, av[2][i]);
			i++;
		}
		signal(SIGUSR2, confirm_msg);
		emetteur(pid, '\0');
	}
	else
	{
		ft_printf("ERROR : arg most be 3 ./exe / pid / [string-char] \n");
		return (1);
	}
	return (0);
}
