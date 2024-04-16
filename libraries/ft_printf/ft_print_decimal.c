/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 21:27:30 by mstefano          #+#    #+#             */
/*   Updated: 2023/11/17 19:23:11 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_count(int n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
		digit = 1;
	while (n)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		d_count;
	long	n1;

	n1 = n;
	d_count = ft_digit_count(n1);
	result = (char *)malloc(sizeof(char) * (d_count + 1));
	if (!result)
		return (NULL);
	result[d_count] = '\0';
	if (n1 == 0)
		result[0] = '0';
	if (n1 < 0)
	{
		result[0] = '-';
		n1 = -n1;
	}
	while (n1 && d_count--)
	{
		result[d_count] = (n1 % 10) + 48;
		n1 /= 10;
	}
	return (result);
}

int	ft_print_decimal(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_str(num);
	if (len < 0)
		return (-1);
	free(num);
	return (len);
}
