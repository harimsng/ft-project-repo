/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:43:06 by hseong            #+#    #+#             */
/*   Updated: 2021/10/23 22:34:27 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../includes/ft_dict.h"

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_putnbr(int num);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
long long int	ft_atou(char *str);

char			**ft_split(char *str, char *charset);
t_dict			*ft_strs_to_tab(int size, char **strs);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strndup(char *str, unsigned int size);
char			*ft_strdup(char *str);

void			ft_swap(int *a, int *b);
int				ft_isspace(char c);

#endif
