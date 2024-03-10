#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main()
{
    string brain = "HI THIS IS BRAIN"; //A string variable initialized to "HI THIS IS BRAIN"
    string *stringPTR = &brain; //stringPTR: A pointer to the string
    string &stringREF = brain; //stringREF: A reference to the string
    cout << "The memory address of the string variable is : " << &brain << endl;
    cout << "The memory address held by stringPTR is : " << stringPTR << endl;
    cout << "The memory address held by stringREF is : " << &stringREF << endl;
    cout << "The value of the string variable is : " << brain << endl;
    cout << "The value pointed to by stringPTR is : " << *stringPTR << endl;
    cout << "The value pointed to by stringREF is : " << stringREF << endl;
    return 0;
}