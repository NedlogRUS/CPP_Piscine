#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

PhoneBook::PhoneBook() {}

void PhoneBook::startPB() const
{
    cout << "Enter command (ADD, SEARCH, EXIT): " << endl;
}

void PhoneBook::addContact() const
{
    cout << "ADD" << endl;
}

//void PhoneBook::displayContacts() const
//
//void PhoneBook::displayContact(int index) const
