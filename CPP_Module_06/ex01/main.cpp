#include "Serializer.hpp"
#include <iostream>
#include <cassert>

int main() {
    Data data = {10, 20.5f, 'a'};
    Data* ptr = &data;

    std::cout << "Original Data: " << ptr->a << ", " << ptr->b << ", " << ptr->c << std::endl;

    uintptr_t serialized = Serializer::serialize(ptr);
    std::cout << "Serialized Data: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data: " << deserialized->a << ", " << deserialized->b << ", " << deserialized->c << std::endl;

    assert(deserialized == ptr);
    std::cout << "My class works as expected, I'm awesome!" << std::endl;

    return 0;
}