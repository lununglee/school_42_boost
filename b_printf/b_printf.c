/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:25:15 by llee              #+#    #+#             */
/*   Updated: 2018/10/03 14:10:15 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		b_printf(const char *format, ...)
{
	va_list ap;
	int		i;

	va_start(ap, format);
	i = b_printf_parse(format, ap);
	va_end(ap);
	return (i);
}

int		b_printf_parse(const char *format, va_list ap)
{
	int		count;

	count = 0;
	b_printf_parse_2(format, ap, &count);
	return (count);
}

int		b_printf_parse_2(const char *format, va_list ap, int *count)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (0);
			else if (*format == 's')
				b_printf_str(ap, count);
			else if (*format == 'c' || *format == 'd' || *format == 'i')
				b_printf_int_char(format, ap, count);
			else if (*format == 'o' || *format == 'u' || *format == 'x')
				b_printf_unsigned_int(format, ap, count);
			else if (*format == 'p')
				b_printf_unsigned_long(ap, count);
			format++;
		}
		else
		{
			while (*format != '\0' && *format != '%')
				ft_putchar(*format++, count);
		}
	}
	return (*count);
}
