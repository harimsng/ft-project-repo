/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:13:57 by hseong            #+#    #+#             */
/*   Updated: 2022/02/25 22:36:07 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <unistd.h>

void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr_space(int num);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t size);

#endif
