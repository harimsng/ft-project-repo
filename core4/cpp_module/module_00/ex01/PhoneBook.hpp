/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:20:47 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 14:43:10 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONE_BOOK_HPP_
#define _PHONE_BOOK_HPP_

#include "Contact.hpp"

#define MAX_CONTACT (8)

class PhoneBook
{
private:
	Contact		m_phoneBook[MAX_CONTACT];
	int			m_start;
	int			m_size;

	bool		getStringInput(char str[MAX_NAME]);
	void		printContactInfo(int index);
	void		printInternal(Contact *contact);

public:
	PhoneBook();
	~PhoneBook();

	//
	bool	addContact(void);
	bool	searchContact(void);
	void	showPhoneBook(void);
};

#endif
