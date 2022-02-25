/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:02:37 by hseong            #+#    #+#             */
/*   Updated: 2022/02/25 22:35:53 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static const char		*g_inst_string[11] =
{
	"pa",
	"pb",
	"sa",
	"sb",
	"ss",
	"ra",
	"rb",
	"rr",
	"rra",
	"rrb",
	"rrr"
};

// a = 97, b = 98, p = 70, r = 72, s = 73
// sa -> s + 26 * a = 2595 % 17 -> 11
// sb -> s + 26 * b = 2621 % 17 -> 3
// ss -> s + 26 * s = 1971 % 17 -> 16
// pa -> p + 26 * a = 2592 % 17 -> 8
// pb -> p + 26 * b = 2618 % 17 -> 0
// ra -> r + 26 * a = 2594 % 17 -> 10
// rra-> r + 26 * r + 26^2 * a = 67516 % 17 -> 9
// rb -> r + 26 * b = 2620 % 17 -> 2
// rrb-> r + 26 * r + 26^2 * b = 68192 % 17 -> 5
// rr -> r + 26 * r = 1944 % 17 -> 6
// rrr-> r + 26 * r + 26^2 * r = 50616 % 17 -> 7
static const inst_func	g_inst_table[17] =
{
	pb,
	NULL,
	rb,
	sb,
	NULL,
	rrb,
	rr,
	rrr,
	pa,
	rra,
	ra,
	sa,
	NULL,
	NULL,
	NULL,
	NULL,
	ss
};

static t_bool	verify_inst(char *buf);
static size_t	get_key(char *buf);

t_bool	check_inst(t_deque *a_deque, t_deque *b_deque)
{
	t_deque	*deque_set[2];
	char	*inst_buf;

	deque_set[0] = a_deque;
	deque_set[1] = b_deque;
	inst_buf = get_next_line(0);
	while (inst_buf != NULL)
	{
		if (verify_inst(inst_buf) == FALSE)
			return (1);
		g_inst_table[get_key(inst_buf)](deque_set);
		inst_buf = get_next_line(0);
	}
	return (sort_check(a_deque));
}

t_bool	verify_inst(char *buf)
{
	size_t	idx;
	t_bool	result;

	if (ft_strlen(buf) > 3)
		return (FALSE);
	result = FALSE;
	idx = 0;
	while (idx < 11)
	{
		if (ft_strncmp(g_inst_string[idx], buf, 3) == 0)
			result = TRUE;
		++idx;
	}
	return (result);
}

static size_t	get_key(char *buf)
{
	return ((buf[0]
			+ 26 * buf[1]
			+ 26 * 26 * buf[2]) % 17);
}
