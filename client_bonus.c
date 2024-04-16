/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:22:14 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/15 18:52:36 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/Libft/libft.h"
#include "libraries/ft_printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>


void receive_ack(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("\033[1;31mA");
		ft_printf("\033[1;32mC");
		ft_printf("\033[1;33mK");
		ft_printf("\033[1;34mN");
		ft_printf("\033[1;35mO");
		ft_printf("\033[1;36mW");
		ft_printf("\033[1;37mL");
		ft_printf("\033[1;36mE");
		ft_printf("\033[1;35mD");
		ft_printf("\033[1;34mG");
		ft_printf("\033[1;33mE");
		ft_printf("\033[1;32mD");
		ft_printf("\033[1;31m!\n");
		
}

void	send_signal(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(70);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			send_signal(pid, argv[2][i]);
			i++;
		}
		signal(SIGUSR2, receive_ack);
		send_signal(pid, '\0');
	}
	else
		return (ft_printf("ERROR"), 1);
	return (0);
}
