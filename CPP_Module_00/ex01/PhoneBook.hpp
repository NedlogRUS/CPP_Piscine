#ifndef CPP_PHONEBOOK_HPP
#define CPP_PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int contactCount;

public:
    PhoneBook();

    void addContact(const Contact &newContact);
    void displayContacts() const;
    void displayContact(int index) const;
};

#endif //CPP_PHONEBOOK_HPP
