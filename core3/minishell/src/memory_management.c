/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:04:57 by hseong            #+#    #+#             */
/*   Updated: 2022/05/04 19:10:04 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

void	minishell_free_token(t_token_arr *token_arr_ptr)
{
	t_token_arr	token_arr;
	size_t		idx;

	token_arr = *token_arr_ptr;
	idx = 0;
	while (token_arr[idx])
	{
		free(token_arr[idx]);
		++idx;
	}
	free(token_arr);
	*token_arr_ptr = NULL;
}
