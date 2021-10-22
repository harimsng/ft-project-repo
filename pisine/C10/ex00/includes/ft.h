/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:15:39 by hseong            #+#    #+#             */
/*   Updated: 2021/10/22 21:15:40 by hseong           ###   ########.kr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>

# include <sys/stat.h>

# include <fcntl.h>

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int num);
void	ft_swap(int a, int b);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);

#endif
