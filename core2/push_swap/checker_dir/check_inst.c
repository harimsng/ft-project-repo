/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:02:37 by hseong            #+#    #+#             */
/*   Updated: 2022/03/01 18:19:40 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static const char			*g_inst_string[11]
	= {"pa\n", "pb\n", "sa\n", "sb\n", "ss\n", "ra\n", "rb\n", "rr\n",
	"rra\n", "rrb\n", "rrr\n"};

static const t_inst_func	g_inst_table[31]
	= {
	NULL,
	ra,
	sa,
	NULL,
	NULL,
	ss,
	NULL,
	rrr,
	NULL,
	rr,
	rrb,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	rra,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	pb,
	NULL,
	rb,
	sb,
	NULL,
	pa,
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
		if (verify_inst(inst_buf) == ERROR_BIT)
			return (ERROR_BIT);
		g_inst_table[get_key(inst_buf)](deque_set);
		inst_buf = get_next_line(0);
	}
	return (!sort_check(a_deque) || (b_deque->size != 0));
}

t_bool	verify_inst(char *buf)
{
	size_t	idx;
	size_t	len;
	t_bool	result;

	len = ft_strlen(buf);
	if (len > 4 || len < 3 || buf[len - 1] != '\n')
		return (ERROR_BIT);
	result = ERROR_BIT;
	idx = 0;
	while (idx < 11)
	{
		if (ft_strncmp(g_inst_string[idx], buf, 3 + (idx > 7)) == 0)
			return (OK_BIT);
		++idx;
	}
	return (result);
}

static size_t	get_key(char *buf)
{
	if (buf[2] == '\n')
		buf[2] = 0;
	return ((buf[0]
			+ 26 * buf[1]
			+ 26 * 26 * buf[2]) % 31);
}
// a = 97, b = 98, p = 112, r = 114, s = 115
// sa -> s + 26 * a = 2637 % 31 -> 2
// sb -> s + 26 * b = 2663 % 31 -> 11
// ss -> s + 26 * s = 3105 % 31 -> 16
// pa -> p + 26 * a = 2635 % 31 -> 8
// pb -> p + 26 * b = 2660 % 31 -> 0
// ra -> r + 26 * a = 2636 % 31 -> 10
// rra-> r + 26 * r + 26^2 * a = 68650 % 31 -> 9
// rb -> r + 26 * b = 2662 % 31 -> 2
// rrb-> r + 26 * r + 26^2 * b = 69325 % 31 -> 5
// rr -> r + 26 * r = 3078 % 31 -> 6
// rrr-> r + 26 * r + 26^2 * r = 80142 % 31 -> 7
