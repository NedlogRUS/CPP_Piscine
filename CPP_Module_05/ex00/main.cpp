#include "Bureaucrat.hpp"

int main() {
    Bureaucrat *bureaucrat = nullptr;
    try {
        bureaucrat = new Bureaucrat("Bureaucrat", 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    delete bureaucrat;
    return (0);
}
