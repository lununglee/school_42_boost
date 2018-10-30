/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_structs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:38:33 by llee              #+#    #+#             */
/*   Updated: 2018/10/15 20:38:34 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	b_init(t_var *var)
{
	var->flag = NULL;
	var->i = 0;
	var->j = 0;
	var->number_of_digits = 0;
	var->prev = 0;
	var->prev2 = 0;
	var->prev3 = 0;
	var->intbuf = 0;
	var->charbuf = NULL;
	var->number_of_files = 0;
	var->date_counter = 4;
	var->block_size = 0;
	var->file = NULL;
	var->dir = NULL;
	var->ltag = 0;
	var->atag = 0;
	var->rtag = 0;
	var->ttag = 0;
	var->dirtag = 0;
}

void	b_reinit(t_var *var)
{
	var->i = 0;
	var->j = 0;
	var->number_of_digits = 0;
	var->prev = 0;
	var->prev2 = 0;
	var->prev3 = 0;
	var->intbuf = 0;
	var->charbuf = NULL;
	var->number_of_files = 0;
	var->date_counter = 4;
	var->block_size = 0;
}

void	b_read_filenum(t_var *var, char *path)
{
	b_strcpy(var->path, path);
	if (!(var->dir = opendir(var->path)))
	{
		printf("ls: %s: %s\n", path, strerror(errno));
		exit(0);
	}
	while ((sd = readdir(var->dir)) != NULL)
		var->number_of_files++;
	closedir(var->dir);
}

void	b_struct_malloc(t_var *var)
{
	if (!(var->file = (t_file*)malloc(sizeof(t_file) *
	(var->number_of_files) + 1)))
		exit(1);
}

void	b_retrieve_info(t_var *var)
{
	var->i = 0;
	if (!(var->dir = opendir(var->path)))
		exit(1);
	while ((sd = readdir(var->dir)) != NULL)
	{
		b_strcat(var->path, "/");
		lstat(b_strcat(var->path, sd->d_name), &buf);
		var->file[var->i].name = strdup(sd->d_name);
		var->file[var->i].block = buf.st_blocks;
		if (var->atag == 0)
		{
			if (var->file[var->i].name[0] != '.')
				var->block_size += var->file[var->i].block;
		}
		else
			var->block_size += var->file[var->i].block;
		var->file[var->i].perm = buf.st_mode;
		var->file[var->i].link = buf.st_nlink;
		var->file[var->i].user = strdup(getpwuid(buf.st_uid)->pw_name);
		var->file[var->i].group = strdup(getgrgid(buf.st_gid)->gr_name);
		var->file[var->i].size = buf.st_size;
		var->file[var->i].my_time = buf.st_mtimespec;
		var->file[var->i].timestamp = strdup(ctime(&buf.st_mtime));
		var->i++;
		b_bzero(var->path + strlen(var->path) - (strlen(sd->d_name) + 1), '0');
	}
	closedir(var->dir);
}
