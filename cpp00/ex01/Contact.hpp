#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;

public:
  void setFirstName(const std::string &newFirstName);
  void setLastName(const std::string &newLastName);
  void setNickName(const std::string &newNickName);
  void setPhoneNumber(const std::string &newPhoneNumber);
  void setDarkestSecret(const std::string &newDarkestSecret);
  std::string	getFirstName(void) const;
  std::string	getLastName(void) const;
  std::string	getNickName(void) const;
  std::string	getPhoneNumber(void) const;
  std::string	getDarkestSecret(void) const;
};

#endif