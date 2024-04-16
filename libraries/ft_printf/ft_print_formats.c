/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_formats.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:01:05 by mstefano          #+#    #+#             */
/*   Updated: 2023/11/12 17:31:46 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_formats(va_list args, const char *format)
{
	int	print_len;

	print_len = 0;
	if (*format == 'c')
		print_len = ft_print_character(va_arg(args, int));
	else if (*format == 's')
		print_len = ft_print_str(va_arg(args, char *));
	else if (*format == 'p')
		print_len = ft_print_ptr(va_arg(args, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		print_len = ft_print_decimal(va_arg(args, int));
	else if (*format == 'u')
		print_len = ft_print_unsigneddecimal(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		print_len = ft_print_hexa((unsigned int)va_arg(args, int), *format);
	else if (*format == '%')
		print_len = ft_print_percent();
	if (print_len < 0)
		return (-1);
	return (print_len);
}
