/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:15:56 by llee              #+#    #+#             */
/*   Updated: 2018/10/15 20:15:57 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	b_sort(t_var *var)
{
	if (var->rtag == 0 && var->ttag == 0)
		b_sort_lexi(var);
	else if (var->rtag == 0 && var->ttag == 1)
		b_sort_time(var);
	else if (var->rtag == 1 && var->ttag == 0)
		b_sort_lexi_rev(var);
	else if (var->rtag == 1 && var->ttag == 1)
		b_sort_time_rev(var);
}

void    b_sort_lexi(t_var *var)
{
	t_file	temp;

	var->i = 0;
	var->j = 0;
	while (var->i < var->number_of_files)
	{
		var->j = var->i + 1;
		while (var->j < var->number_of_files)
		{
			// printf("%i   %s\n", var->j, var->file[var->j].name);
			if (strcmp(var->file[var->i].name, var->file[var->j].name) > 0)
			{
				temp = var->file[var->i];
				var->file[var->i] = var->file[var->j];
				var->file[var->j] = temp;
			}
			var->j++;
		}
		var->i++;
	}
}

void    b_sort_lexi_rev(t_var *var)
{
	t_file	temp;

	var->i = 0;
	var->j = 0;
	while (var->i < var->number_of_files)
	{
		var->j = var->i + 1;
		while (var->j < var->number_of_files)
		{
			if (strcmp(var->file[var->i].name, var->file[var->j].name) < 0)
			{
				temp = var->file[var->i];
				var->file[var->i] = var->file[var->j];
				var->file[var->j] = temp;
			}
			var->j++;
		}
		var->i++;
	}
}

void    b_sort_time(t_var *var)
{
	t_file	temp;

	var->i = 0;
	var->j = 0;
	while (var->i < var->number_of_files)
	{
		var->j = var->i + 1;
		while (var->j < var->number_of_files)
		{
			if (var->file[var->i].my_time.tv_sec <
			var->file[var->j].my_time.tv_sec)
			{
				temp = var->file[var->i];
				var->file[var->i] = var->file[var->j];
				var->file[var->j] = temp;
			}
			else if (var->file[var->i].my_time.tv_sec ==
			var->file[var->j].my_time.tv_sec)
			{
				if (var->file[var->i].my_time.tv_nsec <
				var->file[var->j].my_time.tv_nsec)
				{
					temp = var->file[var->i];
					var->file[var->i] = var->file[var->j];
					var->file[var->j] = temp;
				}
			}
			var->j++;
		}
		var->i++;
	}
}

void    b_sort_time_rev(t_var *var)
{
	t_file	temp;

	var->i = 0;
	var->j = 0;
	while (var->i < var->number_of_files)
	{
		var->j = var->i + 1;
		while (var->j < var->number_of_files)
		{
			if (var->file[var->i].my_time.tv_sec >
			var->file[var->j].my_time.tv_sec)
			{
				temp = var->file[var->i];
				var->file[var->i] = var->file[var->j];
				var->file[var->j] = temp;
			}
			else if (var->file[var->i].my_time.tv_sec ==
			var->file[var->j].my_time.tv_sec)
			{
				if (var->file[var->i].my_time.tv_nsec >
				var->file[var->j].my_time.tv_nsec)
				{
					temp = var->file[var->i];
					var->file[var->i] = var->file[var->j];
					var->file[var->j] = temp;
				}
			}
			var->j++;
		}
		var->i++;
	}
}