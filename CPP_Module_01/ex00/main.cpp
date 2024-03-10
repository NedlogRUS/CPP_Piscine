#include "Zombie.hpp"

Zombie *newZombie(string name);
void randomChump(string name);

int main()
{
    Zombie *Heap = newZombie("Heap");
    Heap->announce();
    delete Heap;
    randomChump("Stack");
//    system("leaks zombie");
    return 0;
}