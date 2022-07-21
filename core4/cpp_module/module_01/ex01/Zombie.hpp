/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:12:32 by hseong            #+#    #+#             */
/*   Updated: 2022/07/20 00:41:25 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ZOMBIE_HPP_
#define _ZOMBIE_HPP_

#include <string>

class	Zombie
{
private:
	std::string	m_name;
public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();

	void	setName(std::string &name);
	void	announce(void);
};

#endif
