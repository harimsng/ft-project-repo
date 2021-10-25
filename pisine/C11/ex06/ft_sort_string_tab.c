/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:57:57 by hseong            #+#    #+#             */
/*   Updated: 2021/10/25 21:59:14 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2);
void	ft_ptrswap(char **s1, char **s2);

void	ft_sort_string_tab(char **tab)
{
	int		idx;
	int		jdx;

	if (!tab || !*tab)
		return ;
	idx = 0;
	while (tab[idx + 1])
	{
		jdx = idx + 1;
		while (tab[jdx])
		{
			if (ft_strcmp(tab[idx], tab[jdx]) > 0)
				ft_ptrswap(tab + idx, tab + jdx);
			++jdx;
		}
		++idx;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_ptrswap(char **s1, char **s2)
{
	char	*temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}
