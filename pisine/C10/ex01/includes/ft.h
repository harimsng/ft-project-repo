/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:26:42 by hseong            #+#    #+#             */
/*   Updated: 2021/10/27 00:52:22 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

// read()
# include <sys/types.h>
# include <sys/stat.h>

// open()
# include <fcntl.h>

// read(), close(), write()
# include <unistd.h>

// errno
# include <sys/errno.h>

// basename()
# include <libgen.h>

// strerror()
# include <string.h>

void	ft_putstr(char *str);
void	ft_puterr(const char *str);

#endif
