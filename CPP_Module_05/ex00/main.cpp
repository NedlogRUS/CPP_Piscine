#include "Bureaucrat.hpp"

int main() {
    Bureaucrat bureaucrat("Ned", 100);
    std::cout << bureaucrat << std::endl;
    try {
        Bureaucrat bureaucrat("Ned", 0);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bureaucrat("Ned", 151);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bureaucrat("Ned", 100);
        bureaucrat.incrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.incrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Bureaucrat bureaucrat("Ned", 100);
        bureaucrat.decrementGrade();
        std::cout << bureaucrat << std::endl;
        bureaucrat.decrementGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
