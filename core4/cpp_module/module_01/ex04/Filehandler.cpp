/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filehandler.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:46:37 by hseong            #+#    #+#             */
/*   Updated: 2022/07/22 23:04:06 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filehandler.hpp"

#define BUFFER_SIZE (128)

Filehandler::Filehandler(const char *from, const char *to)
:
	m_from(from),
	m_to(to),
	m_fail(false)
{
}

bool	Filehandler::openFile(const char *path)
{
	m_inStream.open(path);
	m_outStream.open("." + std::string(path) + ".temp");
	return !(m_inStream.fail() || m_outStream.fail());
}

bool	Filehandler::transformFile(void)
{
	std::string	buffer;
	char		rawBuffer[BUFFER_SIZE];

	if (m_inStream.fail())
		m_fail = true;
	buffer.resize(BUFFER_SIZE);
	while (m_inStream.good())
	{
		m_inStream.read(rawBuffer, BUFFER_SIZE);
		buffer = rawBuffer;
		substitute(buffer);
	}
	return true;
}

bool	Filehandler::substitute(std::string buffer)
{
	size_t	pos = 0;
	size_t	start = 0;

	buffer.resize(m_inStream.gcount());
	pos = buffer.find(m_from);
	while (pos != std::string::npos)
	{
		m_outStream.write(buffer.data() + start, pos - start);
		m_outStream.write(m_to.data(), m_to.size());
		start = pos + m_from.size();
		pos = buffer.find(m_from, start);
	}
	m_outStream.write(buffer.data(), m_inStream.gcount() - start);
	return true;
}

bool	Filehandler::getStatus(void) const
{
	return m_fail;
}
