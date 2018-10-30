/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:35:59 by llee              #+#    #+#             */
/*   Updated: 2018/10/15 20:36:00 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	b_print_list(t_var *var)
{
	var->i = 0;
	printf("total %d\n", var->block_size);
	while (var->i < var->number_of_files)
	{
		if (var->atag == 0)
		{
			if (var->file[var->i].name[0] != '.')
				b_print_list_2(var);
		}
		else
			b_print_list_2(var);
		var->i++;
	}
	while (var->i < var->number_of_files)
	{
		b_print_list_2(var);
		var->i++;
	}
}

void	b_print_list_2(t_var *var)
{
	printf((S_ISDIR(var->file[var->i].perm)) ? "d" : "-");
	printf((var->file[var->i].perm & S_IRUSR) ? "r" : "-");
	printf((var->file[var->i].perm & S_IWUSR) ? "w" : "-");
	printf((var->file[var->i].perm & S_IXUSR) ? "x" : "-");
	printf((var->file[var->i].perm & S_IRGRP) ? "r" : "-");
	printf((var->file[var->i].perm & S_IWGRP) ? "w" : "-");
	printf((var->file[var->i].perm & S_IXGRP) ? "x" : "-");
	printf((var->file[var->i].perm & S_IROTH) ? "r" : "-");
	printf((var->file[var->i].perm & S_IWOTH) ? "w" : "-");
	printf((var->file[var->i].perm & S_IXOTH) ? "x  " : "-  ");
	printf("%*u ", var->prev2, var->file[var->i].link);
	printf("%s  ", var->file[var->i].user);
	printf("%*s  ", var->prev3, var->file[var->i].group);
	printf("%*lld ", var->prev, var->file[var->i].size);
	var->date_counter = 4;
	while (var->date_counter <= 15)
		printf("%c", var->file[var->i].timestamp[var->date_counter++]);
	printf(" %s\n", var->file[var->i].name);
}

void	b_print(t_var *var)
{
	var->i = 0;
	while (var->i < var->number_of_files)
	{
		if (var->atag == 0)
		{
			if (var->file[var->i].name[0] != '.')
				printf("%s\n", var->file[var->i].name);
		}
		else
			printf("%s\n", var->file[var->i].name);
		var->i++;
	}
}