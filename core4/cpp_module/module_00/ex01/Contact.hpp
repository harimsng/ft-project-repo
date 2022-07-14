/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseong <hseong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 05:20:45 by hseong            #+#    #+#             */
/*   Updated: 2022/07/15 05:39:38 by hseong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CONTACT_HPP_
#define _CONTACT_HPP_

#include <iostream>
#include <string>

#define MAX_NAME (64)
#define NUM_DATA (5)

class	Contact
{
public:
	// typedefs for getter and setter tables.
	typedef char	t_fixedArr[MAX_NAME];
	typedef const t_fixedArr	&(t_contactInfoGetter)(void) const;
	typedef void				t_contactInfoSetter(const t_fixedArr);
	typedef t_contactInfoGetter	Contact::*t_contactInfoGetterPtr;
	typedef t_contactInfoSetter	Contact::*t_contactInfoSetterPtr;

	t_contactInfoGetterPtr		m_getterTable[NUM_DATA];
	t_contactInfoSetterPtr		m_setterTable[NUM_DATA];

private:
	int				m_index;

	// data for a contact
	t_fixedArr		m_firstName;
	t_fixedArr		m_lastName;
	t_fixedArr		m_nickname;
	t_fixedArr		m_phoneNumber;
	t_fixedArr		m_darkestSecret;

	void			setGSetterTable(void);

public:
	Contact();
	Contact(int index);
	~Contact();

	// getters & setters for each member
	void				setIndex(int index);
	int					getIndex(void) const;

	void				setFirstName(const char newFirstName[MAX_NAME]);
	const t_fixedArr	&getFirstName(void) const;

	void				setLastName(const char newLastName[MAX_NAME]);
	const t_fixedArr	&getLastName(void) const;

	void				setNickname(const char newNickname[MAX_NAME]);
	const t_fixedArr	&getNickname(void) const;

	void				setPhoneNumber(const char phoneNumber[MAX_NAME]);
	const t_fixedArr	&getPhoneNumber(void) const;

	void				setDarkestSecret(const char darkestSecret[MAX_NAME]);
	const t_fixedArr	&getDarkestSecret(void) const;
};

#endif
