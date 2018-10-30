/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:13:58 by llee              #+#    #+#             */
/*   Updated: 2018/10/22 09:40:58 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	b_wrapfunc(t_var *var)
{
	b_struct_malloc(var);
	b_retrieve_info(var);
	b_sizeformat(var);
	b_linkformat(var);
	b_groupformat(var);
	b_sort(var);
	if (var->ltag == 1)
		b_print_list(var);
	else
		b_print(var);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	t_var	var;

	i = 0;
	j = 0;
	k = 0;
	b_init(&var);
	while (++i < argc)
	{
		if (b_isflag(argv[i]) == 1)
		{
			b_checkflag(&var, argv[j = i]);
			k = i;
		}
		else
			var.dirtag = 1;
 	}
	b_sortargv(argc, argv, j);
	if (var.dirtag == 0)
	{
		b_read_filenum(&var, ".");
		b_wrapfunc(&var);
	}
	else
	{
		while (argv[++k])
		{
			b_read_filenum(&var, argv[k]);
			b_wrapfunc(&var);
			b_reinit(&var);
		}
	}
	return (0);
}
