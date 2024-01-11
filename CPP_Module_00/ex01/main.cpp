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
    PhoneBook PB;
    PB.startPB();
    while(1)
    {
        string command;
//        cin >> command;
        getline(cin, command);
//        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (command == "ADD")
        PB.addContact();
    else if (command == "SEARCH")
            PB.displayContacts();
    else if (command == "EXIT")
        {
            break;
        }
    else
        PB.startPB();
    }
    return 0;
}
