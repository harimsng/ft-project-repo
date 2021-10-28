/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:36:17 by hseong            #+#    #+#             */
/*   Updated: 2021/10/28 18:12:48 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXD_H
# define FT_HEXD_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFLEN (16)

int					print_input(char *filename, int option);

void				ft_putstr(char *str);
void				ft_puterr(char *str);

static const char	*prog_name = "hexdump: ";

#ifndef
