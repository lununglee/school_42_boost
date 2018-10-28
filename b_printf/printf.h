/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:46:49 by llee              #+#    #+#             */
/*   Updated: 2018/09/24 14:32:22 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>

void	ft_putchar(char c, int *count);
void	ft_putstr(char *str, int *count);
void	ft_putnbr(int n, int *count);
int		b_printf(const char *format, ...);
int		b_printf_parse(const char *format, va_list ap);
int		b_printf_parse_2(const char *format, va_list ap, int *count);
int		b_printf_num_conv(long decimal, int base, int *count);
int		b_printf_num_conv_p(unsigned long long int decimal, int *count);
int		b_printf_int_char(const char *format, va_list ap, int *count);
int		b_printf_str(va_list ap, int *count);
int		b_printf_unsigned_int(const char *format, va_list ap, int *count);
int		b_printf_unsigned_long(va_list ap, int *count);

#endif
