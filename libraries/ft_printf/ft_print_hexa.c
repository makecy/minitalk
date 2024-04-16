/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:35:20 by mstefano          #+#    #+#             */
/*   Updated: 2023/11/10 19:39:44 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

void	ft_put_hexa(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_put_hexa(n / 16, format);
		ft_put_hexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_print_character(n + '0');
		else
		{
			if (format == 'x')
				ft_print_character(n - 10 + 'a');
			if (format == 'X')
				ft_print_character(n - 10 + 'A');
		}
	}
}

int	ft_print_hexa(unsigned int n, const char format)
{
	if (n == 0)
		return (write (1, "0", 1));
	ft_put_hexa(n, format);
	return (ft_hexa_len(n));
}
