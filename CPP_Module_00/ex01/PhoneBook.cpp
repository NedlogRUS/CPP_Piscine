#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact(const Contact &newContact)
{
    if (contactCount < 8)
    {
        contacts[contactCount++] = newContact;
    }
    else
    {
        // Replace the oldest contact with the new one
        for (int i = 0; i < 7; ++i)
        {
            contacts[i] = contacts[i + 1];
        }
        contacts[7] = newContact;
    }
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "|   Index  |" << std::setw(10) << "First Name|"
              << std::setw(10) << " Last Name|" << std::setw(10) << " Nickname |" << std::endl;

    for (int i = 0; i < contactCount; ++i)
    {
        std::cout << std::setw(10) << i << std::setw(10) << contacts[i].getFirstName()
                  << std::setw(10) << contacts[i].getLastName() << std::setw(10) << contacts[i].getNickname() << std::endl;
    }
}

void PhoneBook::displayContact(int index) const
{
    if (index >= 0 && index < contactCount)
    {
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    }
    else
    {
        std::cout << "ERROR: Invalid index." << std::endl;
    }
}
