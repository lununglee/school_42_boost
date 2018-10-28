/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:34:15 by llee              #+#    #+#             */
/*   Updated: 2018/10/02 10:29:39 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		b_printf_int_char(const char *format, va_list ap, int *count)
{
	int		i;

	i = va_arg(ap, int);
	if (*format == 'c')
		ft_putchar(i, count);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(i, count);
	return (0);
}

int		b_printf_str(va_list ap, int *count)
{
	char		*string;

	string = va_arg(ap, char *);
	if (!string)
		ft_putstr("(null)", count);
	else
		ft_putstr(string, count);
	return (0);
}

int		b_printf_unsigned_int(const char *format, va_list ap, int *count)
{
	unsigned int	i;
	int				base;

	base = 0;
	i = va_arg(ap, unsigned int);
	if (i == 0)
		ft_putnbr(0, count);
	if (*format == 'o')
		base = 8;
	else if (*format == 'u')
		base = 10;
	else if (*format == 'x')
		base = 16;
	b_printf_num_conv(i, base, count);
	return (0);
}

int		b_printf_unsigned_long(va_list ap, int *count)
{
	unsigned long long int	i;

	i = va_arg(ap, unsigned long long int);
	ft_putstr("0x", count);
	if (i == 0)
		ft_putnbr(0, count);
	b_printf_num_conv_p(i, count);
	return (0);
}
