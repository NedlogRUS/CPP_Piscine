#include "easyfind.hpp"
#include <vector>
#include <list>

int main() {
    int vec_arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(vec_arr, vec_arr + sizeof(vec_arr) / sizeof(int));

    int lst_arr[] = {6, 7, 8, 9, 10};
    std::list<int> lst(lst_arr, lst_arr + sizeof(lst_arr) / sizeof(int));

    try {
        std::cout << "Found " << *easyfind(vec, 3) << " in vector.\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    try {
        std::cout << "Found " << *easyfind(lst, 10) << " in list.\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    try {
        std::cout << "Found " << *easyfind(vec, 6) << " in vector.\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    try {
        std::cout << "Found " << *easyfind(lst, 11) << " in list.\n";
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    return 0;
}
