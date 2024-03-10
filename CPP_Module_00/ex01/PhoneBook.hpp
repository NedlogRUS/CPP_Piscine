#ifndef CPP_PHONEBOOK_HPP
#define CPP_PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int contactCount;
    int count2;

public:
    PhoneBook();

    void startPB() const;
    int addContact();
    int addContact2(int i);
    void displayContacts() const;
    static std::string truncateString(const std::string& str, size_t maxLength);
    void displayContact() const;
};

#endif //CPP_PHONEBOOK_HPP
