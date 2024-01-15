#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

PhoneBook::PhoneBook() : contactCount(0) , count2(0) {}

void PhoneBook::startPB() const
{
    cout << "Enter command (ADD, SEARCH, EXIT): " << endl;
}

void PhoneBook::addContact()
{
    cout << "Enter first name: ";
    string firstName;
    cin >> firstName;
    contacts[contactCount].setFirstName(firstName);

    cout << "Enter last name: ";
    string lastName;
    cin >> lastName;
    contacts[contactCount].setLastName(lastName);

    cout << "Enter nickname: ";
    string nickname;
    cin >> nickname;
    contacts[contactCount].setNickname(nickname);

    cout << "Enter phone number: ";
    string phoneNumber;
    cin >> phoneNumber;
    contacts[contactCount].setPhoneNumber(phoneNumber);

    cout << "Enter darkest secret: ";
    string  darkestSecret;
    cin >> darkestSecret;
    contacts[contactCount].setDarkestSecret(darkestSecret);

    contactCount++;
}

void PhoneBook::displayContacts() const
{
    cout<<"+-------------------------------------------+"<<endl;
    cout << std::setw(10) << "|   Index  |" << std::setw(10) << "First Name|"
              << std::setw(10) << " Last Name|" << std::setw(10) << " Nickname |" << endl;
    cout<<"+-------------------------------------------+"<<endl;
    for (int i = 0; i < contactCount; ++i)
    {
        cout << "|" << std::setw(10) << i + 1 << "|" << std::setw(10) << contacts[i].getFirstName()
                  << "|" << std::setw(10) << contacts[i].getLastName() << "|" << std::setw(10) << contacts[i].getNickname() << "|" << endl;
        cout<<"---------------------------------------------"<<endl;
    }
    cout << "Enter index: ";
}

//void PhoneBook::displayContact(int index) const
