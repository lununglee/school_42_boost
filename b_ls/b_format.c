/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:20:22 by llee              #+#    #+#             */
/*   Updated: 2018/10/15 20:20:23 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	b_sizeformat(t_var *var)
{
	var->i = 0;
	var->prev = 0;
	while (var->i < var->number_of_files)
	{
		var->intbuf = var->file[var->i].size;
		var->number_of_digits = 0;
		while (var->intbuf != 0)
		{
			var->number_of_digits++;
			var->intbuf /= 10;
		}
		if (var->number_of_digits > var->prev)
			var->prev = var->number_of_digits;
		var->i++;
	}
}

void	b_linkformat(t_var *var)
{
	var->i = 0;
	var->prev2 = 0;
	while (var->i < var->number_of_files)
	{
		var->intbuf = var->file[var->i].link;
		var->number_of_digits = 0;
		while (var->intbuf != 0)
		{
			var->number_of_digits++;
			var->intbuf /= 10;
		}
		if (var->number_of_digits > var->prev2)
			var->prev2 = var->number_of_digits;
		var->i++;
	}
}

void	b_groupformat(t_var *var)
{
	var->i = 0;
	var->j = 0;
	var->prev3 = 0;
	while (var->i < var->number_of_files)
	{
		var->charbuf = var->file[var->i].group;
		var->number_of_digits = 0;
		while (var->charbuf[var->j] != '\0')
		{
			var->prev3++;
			var->j++;
		}
		if (var->number_of_digits > var->prev3)
			var->prev3 = var->number_of_digits;
		var->i++;
	}
}