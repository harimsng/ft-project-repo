/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:43:06 by hseong            #+#    #+#             */
/*   Updated: 2021/10/24 19:29:18 by hseong           ###   ########.fr       */
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

void			ft_putstr(char *str);
void			ft_putnbr(int num);
int				ft_strlen(char *str);
long long int	ft_atou(char *str);

char			**ft_split(char *str, char *charset);
t_dict			*ft_strs_to_tab(int size, char **strs);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strndup(char *str, unsigned int size);
char			*ft_strdup(char *str);
void			ptr_swap(char **s1, char **s2);

#endif
