/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 21:33:06 by mstefano          #+#    #+#             */
/*   Updated: 2024/03/30 17:01:06 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_put_ptr(unsigned long n)
{
	int	print_len;

	print_len = 0;
	if (n >= 16)
	{
		print_len = ft_put_ptr(n / 16);
		print_len = ft_put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
		{
			print_len = ft_print_character(n + '0');
			if (print_len < 0)
				return (-1);
		}
		else
		{
			print_len = ft_print_character(n - 10 + 'a');
			if (print_len < 0)
				return (-1);
		}
	}
	return (print_len);
}

int	ft_print_ptr(unsigned long long n)
{
	int	print_len;
	int	ret;

	ret = 0;
	print_len = write(1, "0x", 2);
	if (print_len < 0)
		return (-1);
	ret += print_len;
	if (n == 0)
	{
		print_len = write(1, "0", 1);
		if (print_len < 0)
			return (-1);
		ret += print_len;
	}
	else
	{
		ft_put_ptr(n);
		print_len = ft_ptr_len(n);
		if (print_len < 0)
			return (-1);
		ret += print_len;
	}
	return (ret);
}
