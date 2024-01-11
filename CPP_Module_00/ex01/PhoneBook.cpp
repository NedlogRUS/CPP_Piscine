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

void PhoneBook::addContact()
{
    cout << "Enter first name: ";
    string firstName;
    cin >> firstName;
    contacts[0].setFirstName(firstName);

    cout << "Enter last name: ";
    string lastName;
    cin >> lastName;
    contacts[0].setLastName(lastName);

    cout << "Enter nickname: ";
    string nickname;
    cin >> nickname;
    contacts[0].setNickname(nickname);

    cout << "Enter phone number: ";
    string phoneNumber;
    cin >> phoneNumber;
    contacts[0].setPhoneNumber(phoneNumber);

    cout << "Enter darkest secret: ";
    string  darkestSecret;
    cin >> darkestSecret;
    contacts[0].setDarkestSecret(darkestSecret);
}

void PhoneBook::displayContacts() const
{
    std::cout << std::setw(10) << "|   Index  |" << std::setw(10) << "First Name|"
              << std::setw(10) << " Last Name|" << std::setw(10) << " Nickname |" << std::endl;
}

//void PhoneBook::displayContact(int index) const
