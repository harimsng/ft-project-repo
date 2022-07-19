/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:12:32 by hseong            #+#    #+#             */
/*   Updated: 2022/07/19 15:29:17 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
