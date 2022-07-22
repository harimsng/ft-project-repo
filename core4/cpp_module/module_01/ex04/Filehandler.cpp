/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filehandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:46:37 by hseong            #+#    #+#             */
/*   Updated: 2022/07/23 03:31:35 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Filehandler.hpp"

#define BUFFER_SIZE (128)

Filehandler::Filehandler(const char *from, const char *to)
:
	m_from(from),
	m_to(to),
	m_fail(false)
{
}

bool	Filehandler::getStatus(void) const
{
	return m_fail;
}

void	Filehandler::openFile(const char *in, const char *out)
{
	m_inPathPtr = in;
	m_outPathPtr = out;
	m_inStream.open(in);
	m_outStream.open(out);
	m_fail = !(m_inStream.fail() || m_outStream.fail());
}

void	Filehandler::transformFile(void)
{
	std::string	buffer;
	char		rawBuffer[BUFFER_SIZE];

	if (m_fail)
		return;
	printInfo();
	buffer.resize(BUFFER_SIZE);
	while (m_inStream.good() && m_outStream.good())
	{
		m_inStream.read(rawBuffer, BUFFER_SIZE);
		buffer = rawBuffer;
		substitute(buffer);
	}
}

void	Filehandler::substitute(std::string buffer)
{
	size_t	pos = 0;
	size_t	start = 0;

	buffer.resize(m_inStream.gcount());
	pos = buffer.find(m_from);
	while (m_outStream.good() && pos != std::string::npos)
	{
		m_outStream.write(buffer.data() + start, pos - start);
		m_outStream.write(m_to.data(), m_to.size());
		start = pos + m_from.size();
		pos = buffer.find(m_from, start);
	}
	m_outStream.write(buffer.data() + start, m_inStream.gcount() - start);
}

void	Filehandler::moveFile()
{
	openFile(m_outPathPtr, m_inPathPtr);

	closeFile();
}

void	Filehandler::closeFile()
{
	m_inStream.close();
	m_outStream.close();
}

void	Filehandler::printInfo(void) const
{
	std::cout.width(5);
	std::cout << "from" << " : " << m_from << std::endl;
	std::cout.width(5);
	std::cout << "to" << " : " << m_to << std::endl;
}
