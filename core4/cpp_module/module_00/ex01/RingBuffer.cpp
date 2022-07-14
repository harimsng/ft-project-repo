/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RingBuffer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:24:29 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 05:45:04 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RingBuffer.hpp"

RingBuffer::RingBuffer():
	m_start(0),
	m_size(0)
{
}

RingBuffer::~RingBuffer()
{
}

void	RingBuffer::pushBack(t_item item)
{
	if (m_size == MAX_SIZE)
		popFront();
	m_storage[(m_start + ++m_size) % MAX_SIZE] = item;
}

RingBuffer::t_item	RingBuffer::popFront(void)
{
	int	oldStart = m_start;

	if (m_size == 0)
		return 0;
	--m_size;
	m_start = (m_start + 1) % MAX_SIZE;
	return m_storage[oldStart];
}

int	RingBuffer::getSize(void) const
{
	return m_size;
}
