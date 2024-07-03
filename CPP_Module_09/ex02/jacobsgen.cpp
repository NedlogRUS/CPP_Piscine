#include <iostream>

struct jacobs {
    int prevprev;
    int prev;
    jacobs() : prevprev(1), prev(1) {}
    int gen() {
        int curr = prev + 2 * prevprev;

        prevprev = prev;
        prev = curr;

        return curr;
    }
};

struct indicies {
    int max_included;
    int min_excluded;
    int current;
    jacobs j;
    indicies() : max_included(1), min_excluded(0), current(1) {
    }
    int gen() {
        int result = current;
        current--;
        if (current == min_excluded) {
            min_excluded = max_included;
            max_included = j.gen();
            current = max_included;
        }
        return result - 1;
    }
};

struct limited {
    indicies in;
    int n;
    limited(int n) : n(n) {}
    int gen() {
        while (true) {
            int i = in.gen();
            if (i < n) return i;
        }
    }
};

//int generateJacobsthalSequence() {
//    {
//        limited in(30);
//        const int count = 30; // Количество чисел для генерации
//        for (int i = 0; i < count; ++i) {
//            std::cout << in.gen() << " ";
//        }
//        std::cout << std::endl;
//
//    }
//
//    return 0;
//}
