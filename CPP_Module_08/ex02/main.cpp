#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    std::cout << "Top element after push: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(42);
    mstack.push(0);
    std::cout << "Stack size after multiple pushes: " << mstack.size() << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "Elements in the stack: ";
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    const MutantStack<int> const_mstack(mstack);
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    MutantStack<int>::const_iterator cite = const_mstack.end();
    std::cout << "Elements in the const stack: ";
    while (cit != cite) {
        std::cout << *cit << " ";
        ++cit;
    }
    std::cout << std::endl;

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "Elements in the stack in reverse order: ";
    while (rit != rite) {
        std::cout << *rit << " ";
        ++rit;
    }
    std::cout << std::endl;

    MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
    std::cout << "Elements in the const stack in reverse order: ";
    while (crit != crite) {
        std::cout << *crit << " ";
        ++crit;
    }
    std::cout << std::endl;

    return 0;
}