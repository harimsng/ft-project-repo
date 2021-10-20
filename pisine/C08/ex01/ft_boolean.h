/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 14:43:19 by hseong            #+#    #+#             */
/*   Updated: 2021/10/20 14:43:19 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define TRUE		(1)
# define FALSE		(0)
# define SUCCESS	(0)
# define EVEN_MSG	("I have an even number of arguments.\n")
# define ODD_MSG	("I have an odd number of arguments.\n")
# define EVEN(nbr)	((nbr + 1) % 2)

typedef char	t_bool;

#endif
