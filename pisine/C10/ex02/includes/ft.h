/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:26:48 by hseong            #+#    #+#             */
/*   Updated: 2021/10/27 01:40:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <libgen.h>

void			ft_putstr(char *str);
void			ft_puterr(const char *str);
int				ft_stoi(char *str);
char			*ft_strdup(char *src);
void			ft_strcpy(char *src, char *dest);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size); 
int				ft_str_is_numeric(char *str);
int				ft_strlen(char *str);

#endif
