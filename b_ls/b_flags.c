/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_flags.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:51:16 by llee              #+#    #+#             */
/*   Updated: 2018/10/15 20:51:17 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		b_isflag(char *flag)
{
	if (flag[0] == '-')
		return (1);
	else
		return (0);
}

void	b_checkflag(t_var *var, char *flag)
{
	int i;

	i = 0;
	while (flag[++i])
	{
		if (flag[i] == 'l')
			var->ltag = 1;
		else if (flag[i] == 'a') 
			var->atag = 1;
		else if (flag[i] == 'r')
			var->rtag = 1;
		else if (flag[i] == 't')
			var->ttag = 1;
	}
}

void    b_sortargv(int argc, char **argv, int index)
{
	char	*temp;
	int 	i;
	int		j;

	if (argc == 2)
		index = 1;
	i = index;
	j = index;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		i++;
	}
}
