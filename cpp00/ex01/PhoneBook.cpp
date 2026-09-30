#include "PhoneBook.hpp"
#include "Contact.hpp"

#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>
#include <cstdlib>

PhoneBook::PhoneBook() {
    this->count = 0;
    this->oldestIndex = 0;
}

void    PhoneBook::addContact(const Contact &contactToAdd) {
    this->contacts[this->oldestIndex] = contactToAdd;
    this->oldestIndex = (this->oldestIndex + 1) % 8;
    if (this->count < 8)
        this->count++;
}

static std::string	truncate(const std::string &str)
{
	if (str.length() > 10)
	{
		return str.substr(0, 9) + ".";
	}
	return str;
}

void    PhoneBook::displayContact(void) const {
	std::string	index_input;

    std::cout << "|" << std::setw(10) << "Index"
              << "|" << std::setw(10) << "First Name"
              << "|" << std::setw(10) << "Last Name"
              << "|" << std::setw(10) << "Nickname"
              << "|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < this->count; i++) {
        std::cout << "|" << std::setw(10) << i
                  << "|" << std::setw(10) << truncate(this->contacts[i].getFirstName())
                  << "|" << std::setw(10) << truncate(this->contacts[i].getLastName())
                  << "|" << std::setw(10) << truncate(this->contacts[i].getNickName())
                  << "|" << std::endl;
    }

	std::cout << "Index of contact: ";
	if (!std::getline(std::cin, index_input))
		return;
	
	if (index_input.length() != 1 || !std::isdigit(index_input[0])) {
		std::cout << "Error: Invalid index." << std::endl;
		return;
	}

	int int_input = index_input[0] - '0';
	if (int_input >= this->count) {
		std::cout << "Error: Index out of range." << std::endl;
		return;
	}

	std::cout << "First Name: " << this->contacts[int_input].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[int_input].getLastName() << std::endl;
	std::cout << "Nickname: " << this->contacts[int_input].getNickName() << std::endl;
	std::cout << "Phone Number: " << this->contacts[int_input].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[int_input].getDarkestSecret() << std::endl;
}

