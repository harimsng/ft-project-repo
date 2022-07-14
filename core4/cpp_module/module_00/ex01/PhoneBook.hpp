/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:20:47 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 05:41:31 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONE_BOOK_HPP_
#define _PHONE_BOOK_HPP_

#include "Contact.hpp"
#include "RingBuffer.hpp"

#define MAX_CONTACT (8)

class PhoneBook
{
private:
	RingBuffer	m_phoneBook;
	bool		getStringInput(char str[MAX_NAME]);
	void		printContactInfo(int index);

public:
	PhoneBook();
	~PhoneBook();

	//
	bool	addContact(void);
	bool	searchContact(void);
};

#endif
