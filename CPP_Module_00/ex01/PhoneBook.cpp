#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

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

int PhoneBook::addContact()
{
    if(contactCount <= 7) {
        if(PhoneBook::addContact2(contactCount))
            return (1);
        contactCount++;
    }
    else if(count2 == 8)
    {
        count2 = 0;
        if(PhoneBook::addContact2(count2))
            return (1);
    }
    else
    {
        if(PhoneBook::addContact2(count2))
            return (1);
        count2++;
    }
    return(0);
}

int PhoneBook::addContact2(int i)
{
    cout << "Enter first name: ";
    string firstName;
    std::getline(cin, firstName);
    if (cin.eof()) return (1);
    contacts[i].setFirstName(firstName);

    cout << "Enter last name: ";
    string lastName;
    std::getline(cin, lastName);
    if (cin.eof()) return 1;
    contacts[i].setLastName(lastName);

    cout << "Enter nickname: ";
    string nickname;
    std::getline(cin, nickname);
    if (cin.eof()) return 1;
    contacts[i].setNickname(nickname);

    cout << "Enter phone number: ";
    string phoneNumber;
    std::getline(cin, phoneNumber);
    if (cin.eof()) return 1;
    contacts[i].setPhoneNumber(phoneNumber);

    cout << "Enter darkest secret: ";
    string  darkestSecret;
    cin >> darkestSecret;
    if (cin.eof()) return 1;
    contacts[i].setDarkestSecret(darkestSecret);
    return(0);
}

void PhoneBook::displayContacts() const
{
    cout<<"+-------------------------------------------+"<<endl;
    cout << std::setw(10) << "|   Index  |" << std::setw(10) << "First Name|"
              << std::setw(10) << " Last Name|" << std::setw(10) << " Nickname |" << endl;
    cout<<"+-------------------------------------------+"<<endl;
    for (int i = 0; i < contactCount; ++i) {
        std::cout << "|" << std::setw(10) << i + 1 << "|"
                  << std::setw(10) << truncateString(contacts[i].getFirstName(), 10) << "|"
                  << std::setw(10) << truncateString(contacts[i].getLastName(), 10) << "|"
                  << std::setw(10) << truncateString(contacts[i].getNickname(), 10) << "|" << std::endl;

        std::cout << "---------------------------------------------" << std::endl;
    }
    PhoneBook::displayContact();
}

std::string PhoneBook::truncateString(const std::string& str, size_t maxLength) {
    if (str.length() <= maxLength) {
        return str;
    } else {
        return str.substr(0, maxLength - 1) + ".";
    }
}

void PhoneBook::displayContact() const
{
    std::cout << "Enter index: ";
    int index;
    std::string userInput;
    std::getline(std::cin, userInput);
    bool isValidInput = true;
    for (size_t i = 0; i < userInput.length(); ++i) {
        if (!isdigit(userInput[i])) {
            isValidInput = false;
            break;
        }
    }
    if (isValidInput) {
        index = atoi(userInput.c_str());
        index--;

        if (index >= 0 && index < contactCount) {
            std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
            std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
            std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
            std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
            std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
            PhoneBook::startPB();
        } else {
            std::cout << "ERROR: Invalid index." << std::endl;
            PhoneBook::startPB();
        }
    } else {
        std::cout << "ERROR: Invalid index. Please enter an integer." << std::endl;
        PhoneBook::startPB();
    }
}
