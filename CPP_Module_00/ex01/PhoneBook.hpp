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
    void addContact();
    void displayContacts() const;

//    void displayContact(int index) const;
};

#endif //CPP_PHONEBOOK_HPP
