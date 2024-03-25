#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const Animal	*arr[8];
    for (int i = 0; i < 4; i++)
        arr[i] = new Cat();
    for (int i = 4; i < 8; i++)
        arr[i] = new Dog();
    for (int i = 0; i < 8; i++)
        delete arr[i];
//    system("leaks Brain");
    return 0;
}