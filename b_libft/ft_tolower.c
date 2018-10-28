/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolwoer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 21:18:14 by llee              #+#    #+#             */
/*   Updated: 2018/09/13 21:19:38 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}