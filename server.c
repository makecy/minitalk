/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:23:18 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/12 18:35:41 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libraries/ft_printf/ft_printf.h"
#include "libraries/Libft/libft.h"

void	receive_signal(int sig)
{
	static unsigned char	c;
	static int				byte;
	
	if (sig == SIGUSR1)
		c |= (1 << byte);
	byte++;
	if (byte == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", c);
		byte = 0;
		c = 0;
	}
}

int main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		return(ft_printf("ERROR"), 1);
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
		pause();
	return (0);
}
