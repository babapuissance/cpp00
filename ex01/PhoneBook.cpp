#include "PhoneBook.hpp"
#include <iomanip>

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"

// constructor of class
PhoneBook::PhoneBook(void) : _count(0), _next(0) {
}

PhoneBook::~PhoneBook(void) {
}

void	PhoneBook::addContact(void) {
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;

	firstName = _getInput(YELLOW "👤 Enter first name: " RESET);
	while (firstName.empty()) {
		firstName = _getInput(YELLOW "👤 Enter first name: " RESET);
	}

	lastName = _getInput(YELLOW "👤 Enter last name: " RESET);
	while (lastName.empty()) {
		lastName = _getInput(YELLOW "👤 Enter last name: " RESET);
	}

	nickname = _getInput(YELLOW "🏷️  Enter nickname: " RESET);
	while (nickname.empty()) {
		nickname = _getInput(YELLOW "🏷️  Enter nickname: " RESET);
	}

	phoneNumber = _getInput(YELLOW "📞 Enter phone number: " RESET);
	while (phoneNumber.empty()) {
		phoneNumber = _getInput(YELLOW "📞 Enter phone number: " RESET);
	}

	darkestSecret = _getInput(YELLOW "🤫 Enter darkest secret: " RESET);
	while (darkestSecret.empty()) {
		darkestSecret = _getInput(YELLOW "🤫 Enter darkest secret: " RESET);
	}

	_contacts[_next].setFirstName(firstName);
	_contacts[_next].setLastName(lastName);
	_contacts[_next].setNickname(nickname);
	_contacts[_next].setPhoneNumber(phoneNumber);
	_contacts[_next].setDarkestSecret(darkestSecret);

	_next = (_next + 1) % 8;
	if (_count < 8)
		_count++;
	
	std::cout << GREEN << "✅ Contact added successfully!" << RESET << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::searchContact(void) const {
	if (_count == 0) {
		std::cout << RED << "📭 No contacts in phonebook." << RESET << std::endl;
		std::cout << std::endl;
		return;
	}

	displayContacts();

	std::string	input = _getInput(CYAN "🔍 Enter index (0-" + std::to_string(_count - 1) + "): " RESET);
	if (input.empty()) {
		std::cout << RED << "❌ Invalid index." << RESET << std::endl;
		std::cout << std::endl;
		return;
	}

	int	index = 0;
	for (size_t i = 0; i < input.length(); i++) {
		if (!std::isdigit(input[i])) {
			std::cout << RED << "❌ Invalid index." << RESET << std::endl;
			std::cout << std::endl;
			return;
		}
		index = index * 10 + (input[i] - '0');
	}

	if (index >= _count) {
		std::cout << RED << "❌ Invalid index." << RESET << std::endl;
		std::cout << std::endl;
		return;
	}

	std::cout << std::endl;
	std::cout << BOLD << CYAN << "📋 Contact Details:" << RESET << std::endl;
	std::cout << "┌─────────────────────────────────────┐" << std::endl;
	std::cout << "│ " << YELLOW << "👤 First name: " << WHITE << _contacts[index].getFirstName() << std::endl;
	std::cout << "│ " << YELLOW << "👤 Last name: " << WHITE << _contacts[index].getLastName() << std::endl;
	std::cout << "│ " << YELLOW << "🏷️  Nickname: " << WHITE << _contacts[index].getNickname() << std::endl;
	std::cout << "│ " << YELLOW << "📞 Phone number: " << WHITE << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "│ " << YELLOW << "🤫 Darkest secret: " << WHITE << _contacts[index].getDarkestSecret() << std::endl;
	std::cout << "└─────────────────────────────────────┘" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::displayContacts(void) const {
	std::cout << std::endl;
	std::cout << BOLD << CYAN << "📇 Contact List:" << RESET << std::endl;
	std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "│" << YELLOW << std::setw(10) << "index" << RESET << "│" << YELLOW << std::setw(10) << "first name" << RESET << "│" << YELLOW << std::setw(10) << "last name" << RESET << "│" << YELLOW << std::setw(10) << "nickname" << RESET << "│" << std::endl;
	std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;

	for (int i = 0; i < _count; i++) {
		std::cout << "│" << WHITE << std::setw(10) << i << RESET << "│";
		_formatField(_contacts[i].getFirstName());
		std::cout << "│";
		_formatField(_contacts[i].getLastName());
		std::cout << "│";
		_formatField(_contacts[i].getNickname());
		std::cout << "│" << std::endl;
	}
	std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}

std::string	PhoneBook::_getInput(const std::string& prompt) const {
	std::string	input;
	
	std::cout << prompt;
	if (!std::getline(std::cin, input)) {
		std::cout << "\nExiting.\n";
		std::exit(0);
	}
	
	// Remove leading and trailing whitespace
	size_t	start = input.find_first_not_of(" \t");
	if (start == std::string::npos) {
		return "";
	}
	size_t	end = input.find_last_not_of(" \t");
	return input.substr(start, end - start + 1);
}

void	PhoneBook::_formatField(const std::string& field) const {
	if (field.length() > 10) {
		std::cout << WHITE << std::setw(10) << (field.substr(0, 9) + ".") << RESET;
	} else {
		std::cout << WHITE << std::setw(10) << field << RESET;
	}
}