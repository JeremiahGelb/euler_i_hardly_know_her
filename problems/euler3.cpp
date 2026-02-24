#include "euler3.hpp"

int64_t euler_3(int64_t max) {
    // not needed for the euler example, but just making it handle even numbers
    while (max % 2 == 0) {
        max /= 2;
    }

    int64_t factor = 3;
    while (true) {
        while (max % factor == 0) {   
            max /= factor;
        }

        if (max == 1) {
            return factor;
        }

        while (max % factor != 0) {
            factor += 2;
        }
    }
    return -1; //  unreachable
}