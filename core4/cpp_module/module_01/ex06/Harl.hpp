/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 17:33:39 by hseong            #+#    #+#             */
/*   Updated: 2022/07/24 17:45:05 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _HARL_
#define _HARL_

#include <string>

#define MSG_NUM (4)

class	Harl
{
	typedef void	(Harl::*t_msgFuncPtr)(void) const;

private: // member
	t_msgFuncPtr	m_FuncTab[MSG_NUM];

public: // member functions
	Harl();
	~Harl();

	int		complain(std::string level) const;
	bool	filter(const std::string level) const;

private: // member functions
	void	debug(void) const;
	void	info(void) const;
	void	warning(void) const;
	void	error(void) const;
};

#endif
