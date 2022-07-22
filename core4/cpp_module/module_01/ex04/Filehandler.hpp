/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filehandler.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:46:35 by hseong            #+#    #+#             */
/*   Updated: 2022/07/23 03:30:24 by hseong           ###   ########.fr       */
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
	const char			*m_inPathPtr;
	const char			*m_outPathPtr;
	bool				m_fail;

	void	substitute(std::string buffer);
	void	printInfo(void) const;

public:
	Filehandler(const char *from, const char *to);

	bool	getStatus(void) const;
	void	openFile(const char *in, const char *out);
	void	moveFile();
	void	transformFile();
	void	closeFile();
};

#endif
