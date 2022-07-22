/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filehandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:46:35 by hseong            #+#    #+#             */
/*   Updated: 2022/07/22 23:03:58 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILEHANDLER_
#define _FILEHANDLER_

#include <fstream>

class	Filehandler
{
private:
	std::ifstream		m_inStream;
	std::ofstream		m_outStream;
	const std::string	m_from;
	const std::string	m_to;
	bool				m_fail;

	bool	substitute(std::string buffer);

public:
	Filehandler(const char *from, const char *to);

	bool	openFile(const char *path);
	bool	transformFile();
	bool	getStatus(void) const;
};

#endif
