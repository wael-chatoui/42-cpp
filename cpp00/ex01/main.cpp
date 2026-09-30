#include "Contact.hpp"
#include "PhoneBook.hpp"

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

static bool	is_empty(const std::string &str) {
	if (str.empty())
		return true;
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isspace(static_cast<unsigned char>(str[i])))
			return false;
	}
	return true;
}

static bool	get_field(const std::string &prompt, std::string &field) {
	while (1) {
		std::cout << prompt;
		if (!std::getline(std::cin, field))
			return false;
		if (!is_empty(field))
			return true;
		std::cout << "Field cannot be empty. Please try again." << std::endl;
	}
}

int main(void) {

	PhoneBook	book;
	std::string	command;

	while (1)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
			break;
		if (command == "ADD") {
			Contact		contactToAdd;
			std::string	firstName;
			std::string	lastName;
			std::string	nickName;
			std::string	phoneNumber;
			std::string	darkestSecret;

			if (!get_field("First name: ", firstName)
				|| !get_field("Last name: ", lastName)
				|| !get_field("Nickname: ", nickName)
				|| !get_field("Phone number: ", phoneNumber)
				|| !get_field("Darkest secret: ", darkestSecret))
				break;
			contactToAdd.setFirstName(firstName);
			contactToAdd.setLastName(lastName);
			contactToAdd.setNickName(nickName);
			contactToAdd.setPhoneNumber(phoneNumber);
			contactToAdd.setDarkestSecret(darkestSecret);
			book.addContact(contactToAdd);
			std::cout << "Contact added successfully!" << std::endl;
		}
		else if (command == "SEARCH") {
			book.displayContact();
		}
		else if (command == "EXIT")
			break;
	}

	return EXIT_SUCCESS;
}