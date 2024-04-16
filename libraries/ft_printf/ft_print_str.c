/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:26:01 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/01 19:37:53 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_srlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
	{
		count++;
	}
	return (count);
}

int	ft_print_str(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		len = write(1, "(null)", 6);
		if (len < 0)
			return (-1);
		return (len);
	}
	else
		len = (write(1, str, ft_srlen(str)));
	if (len < 0)
		return (-1);
	return (len);
}
