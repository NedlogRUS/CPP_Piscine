#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

int main()
{
    PhoneBook phoneBook;

    while (true)
    {
        cout << "Enter command (ADD, SEARCH, EXIT): " << endl;
        string command;
//        cin >> command;
        getline (cin,command);

//        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (command == "ADD")
        {
            Contact newContact;

            cout << "Enter first name: ";
            string firstName;
            cin >> firstName;
            newContact.setFirstName(firstName);

            cout << "Enter last name: ";
            string lastName;
            cin >> lastName;
            newContact.setLastName(lastName);

            cout << "Enter nickname: ";
            string nickname;
            cin >> nickname;
            newContact.setNickname(nickname);

            cout << "Enter phone number: ";
            string phoneNumber;
            cin >> phoneNumber;
            newContact.setPhoneNumber(phoneNumber);

            cout << "Enter darkest secret: ";
//            cin.ignore(); // Ignore the newline character left in the buffer
            string darkestSecret;
//            getline(cin, darkestSecret);
            cin >> darkestSecret;
            newContact.setDarkestSecret(darkestSecret);

            phoneBook.addContact(newContact);
            cout << "Contact added successfully." << endl;
        }
        else if (command == "SEARCH")
        {
            phoneBook.displayContacts();

            int index;
            cout << "Enter index: ";
            cin >> index;

            phoneBook.displayContact(index);
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            cout << "ERROR: Invalid command. Please enter ADD, SEARCH, or EXIT." << endl;
        }
    }

    return 0;
}



//#include "PhoneBook.hpp"
//#include <iostream>
//
//using std::cout;
//using std::endl;
//using std::cin;
//using std::getline;
//using std::string;
//
//int main()
//{
//    string input = "";
//
//    while(true) {
//        cin >> input;
//        if (input.compare("ADD") == 0) {
//            cout << "OK" << endl;
//        }
//        else if (input.compare("EXIT") == 0)
//            break;
//        else
//            cout << "ERROR" << endl;
//    }
//    return (0);
//}