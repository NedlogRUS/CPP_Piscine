#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(){
    int i = 3;
    Zombie *horde = zombieHorde(i, "Ned");

    for(int j = 0; j < i; j++)
        horde[j].announce();
    delete[] horde;
//    system("leaks horde");
    return (0);
}