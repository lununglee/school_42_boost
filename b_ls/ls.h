/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:14:04 by llee              #+#    #+#             */
/*   Updated: 2018/10/15 20:14:05 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>

struct dirent			*sd;
struct stat 			buf;

typedef struct 			s_fileinfo
{
	int					block;
	mode_t				perm;
	nlink_t				link;
	char *				user;
	char *				group;
	off_t				size;
	char *				timestamp;
	struct timespec		my_time;
	char *				name;
}						t_file;

typedef struct          s_var
{
	char				path[512];
	char				*flag;
   	int					i;
	int					j;
	int					number_of_digits;
	int					prev;
	int					prev2;
	int					prev3;
	int					intbuf;
	char				*charbuf;
	int					number_of_files;
	int					date_counter;
	int					block_size;
	t_file				*file;
	DIR 				*dir;
	int					ltag;
	int					atag;
	int					rtag;
	int					ttag;
	int					dirtag;
}                       t_var;

void					b_bzero(void *s, size_t n);
char					*b_strcat(char *dest, char *src);
char					*b_strcpy(char *dest, char *src);

void					b_sizeformat(t_var *var);
void					b_linkformat(t_var *var);
void					b_groupformat(t_var *var);

void					b_sort(t_var *var);
void					b_sort_lexi(t_var *var);
void					b_sort_lexi_rev(t_var *var);
void					b_sort_time(t_var *var);
void					b_sort_time_rev(t_var *var);
void					b_sortargv(int argc, char **argv, int index);

int						b_isflag(char *flag);
void					b_checkflag(t_var *var, char *flag);

void					b_init(t_var *var);
void					b_read_filenum(t_var *var, char *path);
void					b_struct_malloc(t_var *var);
void					b_retrieve_info(t_var *var);
void					b_reinit(t_var *var);

void					b_print_list(t_var *var);
void					b_print_list_2(t_var *var);
void					b_print(t_var *var);

#endif
