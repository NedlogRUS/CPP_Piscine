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
    if (command == "ADD"){
        if(PB.addContact())
            return (1);
        }
    else if (command == "SEARCH")
            PB.displayContacts();
    else if (command == "EXIT")
        {
            break;
        }
    else if (cin.eof())
        return 1;
    else
        PB.startPB();
    }
    return 0;
}
