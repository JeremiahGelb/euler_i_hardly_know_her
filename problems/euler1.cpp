#include "euler1.hpp"

int64_t euler_1_all_integers_branchless(int64_t max) {
    int64_t sum = 0;
    int64_t i = 3;
    for (i = 0; i < max; ++i) {
        sum += i * (i % 3 == 0 || i % 5 == 0);
    }
    return sum;
}

int64_t euler_1_all_integers(int64_t max) {
    int64_t sum = 0;
    int64_t i = 3;
    for (i = 0; i < max; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int64_t euler_1_count_by_branchless(int64_t max) {
    int64_t sum = 0;
    int64_t threes = 3;
    int64_t fives = 5;
    while (threes <= max && fives <= max) {
        sum += (threes < fives) * threes;
        sum += (fives <= threes) * fives;
        auto fives_update = fives + (fives <= threes) * 5;
        threes += (threes <= fives) * 3;
        fives = fives_update;
    }
    return sum;
}

int64_t euler_1_count_by(int64_t max) {
    int64_t sum = 0;
    int64_t threes = 3;
    int64_t fives = 5;
    while (threes <= max && fives <= max) {
        if (threes < fives) {
            sum += threes;
            threes += 3;
            continue;
        }

        if (fives < threes) {
            sum += fives;
            fives += 5;
            continue;
        }

        // divisible by 15
        sum += threes;
        threes += 3;
        fives += 5;
    }
    return sum;
}