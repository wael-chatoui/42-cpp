#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook 
{
    private:
		Contact contacts[8];
		int		count;
		int		oldestIndex;

    public:
		PhoneBook();
		void	addContact(const Contact &contactToAdd);
		void	displayContact(void) const;

};

#endif