#include <iostream>
#include <string>

#define NAME_SIZE (64)

class	Contact
{
	private:
		size_t	_index;
		char	_firstName[NAME_SIZE];
		char	_lastName[NAME_SIZE];
		char	_nickname[NAME_SIZE];
		char	_phoneNumber[NAME_SIZE];
		char	_darkestSecret[NAME_SIZE];
		bool	_getStringInput(char str[NAME_SIZE]);
	public:
		Contact();
		Contact(size_t index);
		~Contact();
		void		setIndex(size_t index);
		size_t		getIndex(void) const;
		void		setFirstName(const char newFirstName[NAME_SIZE]);
		const char	*&getFirstName(void) const;
		void		setLastName(const char newLastName[NAME_SIZE]);
		const char	*&getLastName(void) const;
		void		setNickname(const char newNickname[NAME_SIZE]);
		const char	*&getNickname(void) const;
		void		setPhoneNumber(const char phoneNumber[NAME_SIZE]);
		const char	*&getPhoneNumber(void) const;
		void		setDarkestSecret(const char darkestSecret[NAME_SIZE]);
		const char	*&getDarkestSecret(void) const;
};
