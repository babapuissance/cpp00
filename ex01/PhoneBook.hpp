#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);

	void	addContact(void);
	void	searchContact(void) const;
	void	displayContacts(void) const;

private:
	Contact	_contacts[8];
	int		_count;
	int		_next;

	std::string	_getInput(const std::string& prompt) const;
	void		_formatField(const std::string& field) const;
};

#endif
