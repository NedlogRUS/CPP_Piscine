#include <iostream>
#include "Array.hpp"

int main() {
    Array<int> arr(10);
    for (unsigned int i = 0; i < arr.size(); ++i) {
        arr[i] = i * 2;
    }
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    Array<int> arrCopy = arr;
    for (unsigned int i = 0; i < arr.size(); ++i) {
        arr[i] = i * 3;
    }
    std::cout << "Original array: ";
    for (unsigned int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Copied array: ";
    for (unsigned int i = 0; i < arrCopy.size(); ++i) {
        std::cout << arrCopy[i] << " ";
    }
    std::cout << std::endl;
    try {
        std::cout << arr[100] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}

//#include <iostream>
//#include "Array.hpp"
//
//#define MAX_VAL 750
//int main(int, char**)
//{
//    Array<int> numbers(MAX_VAL);
//    int* mirror = new int[MAX_VAL];
//    srand(time(NULL));
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        const int value = rand();
//        numbers[i] = value;
//        mirror[i] = value;
//    }
//    //SCOPE
//    {
//        Array<int> tmp = numbers;
//        Array<int> test(tmp);
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        if (mirror[i] != numbers[i])
//        {
//            std::cerr << "didn't save the same value!!" << std::endl;
//            return 1;
//        }
//    }
//    try
//    {
//        numbers[-2] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//    try
//    {
//        numbers[MAX_VAL] = 0;
//    }
//    catch(const std::exception& e)
//    {
//        std::cerr << e.what() << '\n';
//    }
//
//    for (int i = 0; i < MAX_VAL; i++)
//    {
//        numbers[i] = rand();
//    }
//    delete [] mirror;//
//    return 0;
//}