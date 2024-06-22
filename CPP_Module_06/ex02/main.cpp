#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        Base* p = generate();
        identify(p);
        identify(*p);
        delete p;
    }
    return 0;
}