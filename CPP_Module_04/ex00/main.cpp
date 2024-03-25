#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wrong = new WrongCat();

    cout << "meta->getType(): " << meta->getType() << endl;
    cout << "j->getType(): " << j->getType() << endl;
    cout << "i->getType(): " << i->getType() << endl;
    cout << "wrong->getType(): " << wrong->getType() << endl;
    meta->makeSound(); //will output the animal sound!
    i->makeSound(); //will output the cat sound!
    j->makeSound(); //will output the dog sound!
    wrong->makeSound();//will output the wrong animal sound!
    delete meta;
    delete j;
    delete i;
    delete wrong;
    return 0;
}