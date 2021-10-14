/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 21:04:53 by hseong            #+#    #+#             */
/*   Updated: 2021/10/14 18:38:53 by hseong           ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

int		alphanumeric(char c);
void	case_changer(char *ptr, int n);

char	*ft_strcapitalize(char *str)
{
	char	*ret;
	int		word_flag;

	if (str == 0)
		return (0);
	word_flag = 0;
	ret = str;
	while (*str != 0)
	{
		if (alphanumeric(*str))
		{
			if (!word_flag)
				case_changer(str, 0);
			else
				case_changer(str, 1);
			word_flag = 1;
		}
		else
			word_flag = 0;
		++str;
	}
	return (ret);
}

int	alphanumeric(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

void	case_changer(char *ptr, int n)
{
	if (n == 0)
	{
		if (*ptr >= 'a' && *ptr <= 'z')
			*ptr -= 32;
	}
	else
	{
		if (*ptr >= 'A' && *ptr <= 'Z')
			*ptr += 32;
	}
}
