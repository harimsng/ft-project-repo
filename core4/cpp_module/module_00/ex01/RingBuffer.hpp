/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RingBuffer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:20:33 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 05:43:36 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RING_BUFFER_HPP_
#define _RING_BUFFER_HPP_

#include "Contact.hpp"

#define MAX_SIZE (8)

class	RingBuffer
{
private:
	typedef Contact	t_item;

public:
	t_item	m_storage[MAX_SIZE];
	int		m_start;
	int		m_size;

	RingBuffer();
	~RingBuffer();

	void	pushBack(t_item item);
	t_item	popFront(void);
	int		getSize(void) const;
};

#endif
