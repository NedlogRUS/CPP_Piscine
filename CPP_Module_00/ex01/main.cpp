//#include <PhoneBook.hpp>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;
using std::getline;

int main()
{
    std::string input = "";

    while(true) {
        cin >> input;
        if (input.compare("ADD") == 0) {
            cout << "OK" << endl;
        }
        else if (input.compare("EXIT") == 0)
            break;
        else
            cout << "ERROR" << endl;
    }
    return (0);
}