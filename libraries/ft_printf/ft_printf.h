/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstefano <mstefano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 14:43:28 by mstefano          #+#    #+#             */
/*   Updated: 2024/04/01 19:37:19 by mstefano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_print_character(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(unsigned long long n);
int		ft_printf(const char *str, ...);
size_t	ft_srlen(const char *s);
int		ft_print_decimal(int n);
int		ft_print_percent(void);
int		ft_print_formats(va_list args, const char *format);
int		ft_print_unsigneddecimal(unsigned int n);
int		ft_print_hexa(unsigned int n, const char format);

#endif
