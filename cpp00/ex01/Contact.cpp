#include "Contact.hpp"
#include <string>

void Contact::setFirstName(const std::string &newFirstName) {
  this->firstName = newFirstName;
}

void Contact::setLastName(const std::string &newLastName) {
  this->lastName = newLastName;
}

void Contact::setNickName(const std::string &newNickName) {
  this->nickName = newNickName;
}

void Contact::setPhoneNumber(const std::string &newPhoneNumber) {
  this->phoneNumber = newPhoneNumber;
}

void Contact::setDarkestSecret(const std::string &newDarkestSecret) {
  this->darkestSecret = newDarkestSecret;
}

std::string Contact::getFirstName(void) const {
    return this->firstName;
}

std::string Contact::getLastName(void) const {
    return this->lastName;
}

std::string Contact::getNickName(void) const {
    return this->nickName;
}

std::string Contact::getPhoneNumber(void) const {
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
    return this->darkestSecret;
}