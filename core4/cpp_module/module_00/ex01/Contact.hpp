#include <iostream>
#include <string>

#define NAME_SIZE (64)
#define NUM_DATA (5)

class	Contact
{
public:
	// typedefs for getter and setter tables.
	typedef char	t_fixedArr[NAME_SIZE];
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

	void				setFirstName(const char newFirstName[NAME_SIZE]);
	const t_fixedArr	&getFirstName(void) const;

	void				setLastName(const char newLastName[NAME_SIZE]);
	const t_fixedArr	&getLastName(void) const;

	void				setNickname(const char newNickname[NAME_SIZE]);
	const t_fixedArr	&getNickname(void) const;

	void				setPhoneNumber(const char phoneNumber[NAME_SIZE]);
	const t_fixedArr	&getPhoneNumber(void) const;

	void				setDarkestSecret(const char darkestSecret[NAME_SIZE]);
	const t_fixedArr	&getDarkestSecret(void) const;
};
