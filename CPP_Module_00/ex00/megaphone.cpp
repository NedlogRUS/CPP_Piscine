#include <iostream>

using std::cout;
using std::endl;

int main(int ac, char **av)
{
    int i = 1;
    int j = 0;
    if (ac == i)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
    else
    {
        while (i < ac)
        {
            while (av[i][j])
            {
                cout << char(toupper(av[i][j]));
                j++;
            }
            j = 0;
            i++;
            if (i < ac)
                cout << " ";
        }
        cout << endl;
    }
    return(0);
}