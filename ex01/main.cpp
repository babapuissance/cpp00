#include "PhoneBook.hpp"
#include <iostream>
#include <string>

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

int	main(void) {
	PhoneBook	phonebook;
	std::string	command;

	std::cout << BOLD << CYAN << "╔══════════════════════════════════════╗" << std::endl;
	std::cout << "║" << YELLOW << "      📱 My Awesome PhoneBook 📱      " << CYAN << "║" << std::endl;
	std::cout << "╚══════════════════════════════════════╝" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << GREEN << "Available commands:" << std::endl;
	std::cout << "  " << YELLOW << "ADD" << WHITE << "    - Add a new contact" << std::endl;
	std::cout << "  " << YELLOW << "SEARCH" << WHITE << " - Search contacts" << std::endl;
	std::cout << "  " << YELLOW << "EXIT" << WHITE << "   - Quit program" << RESET << std::endl;
	std::cout << std::endl;

	while (true) {
		std::cout << BOLD << BLUE << "PhoneBook" << RESET << "> ";
		if (!std::getline(std::cin, command)) {
			std::cout << std::endl;
			std::cout << BOLD << RED << "👋 Goodbye!" << RESET << std::endl;
			break;
		}

		if (command == "ADD") {
			phonebook.addContact();
		} else if (command == "SEARCH") {
			phonebook.searchContact();
		} else if (command == "EXIT") {
			std::cout << std::endl;
			std::cout << BOLD << GREEN << "👋 Thank you for using My Awesome PhoneBook!" << std::endl;
			std::cout << "Goodbye!" << RESET << std::endl;
			break;
		} else if (!command.empty()) {
			std::cout << RED << "❌ Invalid command. Available commands: ADD, SEARCH, EXIT" << RESET << std::endl;
		}
	}

	return 0;
}