#include "Contact.hpp"

#define MAX_CONTACT (8)

class PhoneBook
{
private:
	Contact	m_phoneBook[MAX_CONTACT + 1];
	int		m_phoneBookStartIdx;
	int		m_phoneBookSize;
	bool	getStringInput(char str[NAME_SIZE]);
	void	printContactInfo(int index);

public:
	PhoneBook();
	~PhoneBook();

	//
	bool	addContact(void);
	bool	searchContact(void);
};
