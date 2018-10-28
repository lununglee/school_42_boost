/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_printf_itoa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 13:43:18 by llee              #+#    #+#             */
/*   Updated: 2018/09/24 13:54:31 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		b_printf_num_conv(long decimal, int base, int *count)
{
	int		quotient;
	int		remainder;

	quotient = decimal / base;
	remainder = decimal % base;
	if (decimal == 0)
		return (0);
	decimal = quotient;
	b_printf_num_conv(decimal, base, count);
	if (remainder >= 10)
		ft_putchar(remainder + 87, count);
	else
		ft_putnbr(remainder, count);
	return (0);
}

int		b_printf_num_conv_p(unsigned long long int decimal, int *count)
{
	unsigned long long int	quotient;
	unsigned long long int	remainder;
	int						base;

	base = 16;
	quotient = decimal / base;
	remainder = decimal % base;
	if (decimal == 0)
		return (0);
	decimal = quotient;
	b_printf_num_conv_p(decimal, count);
	if (remainder >= 10)
		ft_putchar(remainder + 87, count);
	else
		ft_putnbr(remainder, count);
	return (0);
}
