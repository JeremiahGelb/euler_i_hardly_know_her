#include "euler2.hpp"

int64_t euler_2(int64_t max) {
    int64_t sum = 0;

    auto cur = 1;
    auto last = 0;
    auto tmp = 0;
    while (cur <= max) {
        if (cur % 2 == 0) {
            sum += cur;
        }
        tmp = cur;
        cur = cur + last;
        last = tmp;
    }
    return sum;
}