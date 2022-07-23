/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Substitutor.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:46:35 by hseong            #+#    #+#             */
/*   Updated: 2022/07/23 17:25:10 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILEHANDLER_
#define _FILEHANDLER_

#include <fstream>

class	Substitutor
{
private:
	std::ifstream		m_inStream;
	std::ofstream		m_outStream;
	const std::string	m_from;
	const std::string	m_to;
	std::string			m_pathPtr;
	std::string			m_tempPathPtr;

	void	transfer(const char *rawBuffer);
	void	printInfo(void) const;

public:
	Substitutor(const char *from, const char *to);
	~Substitutor(void);

	bool	isFail(void) const;
	void	openFile(const char *path);
	void	copyFile(void);
	void	transformFile(void);
	void	closeFile(void);
};

#endif
