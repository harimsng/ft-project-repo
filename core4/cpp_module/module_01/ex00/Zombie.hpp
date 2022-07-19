/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:12:32 by hseong            #+#    #+#             */
/*   Updated: 2022/07/18 18:17:47 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class	Zombie
{
private:
	std::string	m_Name;
public:
	Zombie();
	Zombie(const std::string &name);
	~Zombie();

	void	announce(void);
};
