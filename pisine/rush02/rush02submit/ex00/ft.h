/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejo <hyejo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 10:06:29 by hyejo             #+#    #+#             */
/*   Updated: 2021/10/24 21:46:55 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dict
{
	long long	num;
	char		*name;
}	t_dict;

typedef struct s_dicts
{
	int		size;
	t_dict	*dicts;
}	t_dicts;

t_dicts					ft_get_dicts(char *file);
int						ft_get_dict_size(char *file);
long long				get_dict_num(char *file, int index);
char					*get_dict_name(char *file, int index);
char					ft_pass_num(int fd);
int						ft_get_name_len(char *file, int index);
void					ft_pass(int fd, int index);
long long				ft_atoi(char *str);
void					ft_print_num(long long num, t_dicts dicts);
void					ft_putstr(char *str);

#endif
