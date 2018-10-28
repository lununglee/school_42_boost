/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 11:21:30 by llee              #+#    #+#             */
/*   Updated: 2018/09/21 11:21:34 by llee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>

int		ft_isdigit(int c);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *str, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);

#endif
