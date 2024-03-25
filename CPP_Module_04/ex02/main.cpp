#include "Cat.hpp"
#include "Dog.hpp"

int main() {
    const Animal	*arr[2];
    for (int i = 0; i < 1; i++)
        arr[i] = new Cat();
    for (int i = 1; i < 2; i++)
        arr[i] = new Dog();
    for (int i = 0; i < 2; i++)
        delete arr[i];
//    Animal *animal = new Animal(); // This should not compile because Animal is an abstract class
//    system("leaks Brain");
    return 0;
}