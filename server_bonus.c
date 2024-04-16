/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:22:11 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/15 18:24:00 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libraries/Libft/libft.h"
#include "libraries/ft_printf/ft_printf.h"
#include <signal.h>

void	receive_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				byte;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << byte);
	byte++;
	if (byte == 8)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_printf("%c", c);
		byte = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = receive_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	if (argc != 1)
		return (ft_printf("ERROR"), 1);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
