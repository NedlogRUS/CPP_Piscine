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

void PhoneBook::addContact()
{
    if(contactCount <= 7) {
        PhoneBook::addContact2(contactCount);
        contactCount++;
    }
    else if(count2 == 8)
    {
        count2 = 0;
        PhoneBook::addContact2(count2);
    }
    else
    {
        PhoneBook::addContact2(count2);
        count2++;
    }
}

void PhoneBook::addContact2(int i)
{
    cout << "Enter first name: ";
    string firstName;
    cin >> firstName;
    contacts[i].setFirstName(firstName);

    cout << "Enter last name: ";
    string lastName;
    cin >> lastName;
    contacts[i].setLastName(lastName);

    cout << "Enter nickname: ";
    string nickname;
    cin >> nickname;
    contacts[i].setNickname(nickname);

    cout << "Enter phone number: ";
    string phoneNumber;
    cin >> phoneNumber;
    contacts[i].setPhoneNumber(phoneNumber);

    cout << "Enter darkest secret: ";
    string  darkestSecret;
    cin >> darkestSecret;
    contacts[i].setDarkestSecret(darkestSecret);
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

    // Check if the input contains only digits
    bool isValidInput = true;
    for (size_t i = 0; i < userInput.length(); ++i) {
        if (!isdigit(userInput[i])) {
            isValidInput = false;
            break;
        }
    }

    if (isValidInput) {
        index = atoi(userInput.c_str()); // Convert string to integer
        index--; // Adjust index to match array index

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

//void PhoneBook::displayContact() const
//{
//    std::cout << "Enter index: ";
//    int index;
//    if (std::cin >> index) {
//        index--;
//        if (index >= 0 && index < contactCount) {
//            std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
//            std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
//            std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
//            std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
//            std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
//        } else {
//            std::cout << "ERROR: Invalid index." << std::endl;
//        }
//    }
//    else {
//        std::cin.clear();
//        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//        std::cout << "ERROR: Invalid index. Please enter an integer." << std::endl;
//    }
//}
