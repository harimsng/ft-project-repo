/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Substitutor.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:46:37 by hseong            #+#    #+#             */
/*   Updated: 2022/07/23 19:28:15 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Substitutor.hpp"

#define BUFFER_SIZE (8)

Substitutor::Substitutor(const char *from, const char *to)
:
	m_from(from),
	m_to(to)
{
}

Substitutor::~Substitutor()
{
}

bool	Substitutor::isFail(void) const
{
	return m_inStream.fail() || m_outStream.fail();
}

void	Substitutor::openFile(const char *path)
{
	if (m_from.size() > BUFFER_SIZE - 1)
	{
		std::cout << "pattern is too long. ";
		std::cout << "miniSed can handle less than ";
		std::cout << BUFFER_SIZE << " characters ( == BUFFER_SIZE ).\n";
		m_inStream.setstate(std::ios_base::failbit);
		return;
	}
	m_pathPtr = path;
	m_tempPathPtr = "." + m_pathPtr + ".temp";
	copyFile();
	m_inStream.open(m_tempPathPtr.data());
	m_outStream.open(m_pathPtr.data(), std::ios_base::trunc);
}

void	Substitutor::transformFile(void)
{
	char	rawBuffer[BUFFER_SIZE];

	if (isFail())
		return;
	while (m_inStream.good() && m_outStream.good())
	{
		m_inStream.read(rawBuffer, BUFFER_SIZE);
		transfer(rawBuffer);
	}
	if (m_inStream.eof())
	{
		m_inStream.clear();
		m_inStream.setstate(std::ios_base::eofbit);
	}
}

/*
 * buffersize = 9
 * from = abcabc, to = 123123
 * abcabcabcabcabcabc
 *
 * */
void	Substitutor::transfer(const char *rawBuffer)
{
	std::string	buffer(rawBuffer, m_inStream.gcount());
	size_t		pos = 0;
	size_t		start = 0;
	size_t		nextReadPoint = 0;

	pos = buffer.find(m_from);
	while (m_outStream.good() && pos != std::string::npos)
	{
		m_outStream.write(buffer.data() + start, pos - start);
		m_outStream.write(m_to.data(), m_to.size());
		start = pos + m_from.size();
		pos = buffer.find(m_from, start);
	}
	if (m_inStream.gcount() != BUFFER_SIZE)
	{
		m_outStream.write(buffer.data() + start, m_inStream.gcount() - start);
		return;
	}
	nextReadPoint = BUFFER_SIZE - m_from.size() + 1;
	if (start >= nextReadPoint)
		nextReadPoint = start;
	else
		m_outStream.write(buffer.data() + start, nextReadPoint - start);
	m_inStream.seekg(nextReadPoint - BUFFER_SIZE, std::ios_base::cur);
}

void	Substitutor::copyFile()
{
	char	buffer[BUFFER_SIZE];

	m_inStream.open(m_pathPtr.data());
	m_outStream.open(m_tempPathPtr.data(), std::ios_base::trunc);
	while (m_inStream.good())
	{
		m_inStream.read(buffer, BUFFER_SIZE);
		m_outStream.write(buffer, m_inStream.gcount());
	}
	closeFile();
}

void	Substitutor::closeFile()
{
	m_inStream.close();
	m_outStream.close();
}

void	Substitutor::printInfo(void) const
{
	std::cout.width(5);
	std::cout << "from" << " : " << m_from << std::endl;
	std::cout.width(5);
	std::cout << "to" << " : " << m_to << std::endl;
}
