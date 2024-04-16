/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigneddecimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:41:48 by mstefano          #+#    #+#             */
/*   Updated: 2023/11/08 00:03:37 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digit_count(unsigned int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

char	*ft_uitoa(unsigned int n)
{
	char	*result;
	int		d_count;

	d_count = ft_digit_count(n);
	result = (char *)malloc(sizeof(char) * (d_count + 1));
	if (!result)
		return (0);
	result[d_count] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n != 0)
	{
		result[d_count - 1] = (n % 10) + 48;
		n /= 10;
		d_count--;
	}
	return (result);
}

int	ft_print_unsigneddecimal(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_uitoa(n);
	len = ft_print_str(num);
	free(num);
	return (len);
}
