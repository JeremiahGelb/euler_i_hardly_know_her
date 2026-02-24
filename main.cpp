#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include <functional>
#include <string>

#include "euler1.hpp"
#include "euler2.hpp"
#include "euler3.hpp"
#include "euler4.hpp"


template<typename ToDuration>
void time_euler(std::string name, std::function<int64_t(int64_t)> euler, int64_t max) {
    auto t1 = std::chrono::high_resolution_clock::now();
    auto result = euler(max);
    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<ToDuration>(t2 - t1);
    std::cout << name << " final result = " << result << " in " << duration << std::endl;
}

int main() {
    time_euler<std::chrono::nanoseconds>("euler_1", euler_1_count_by_branchless, 1000);
    time_euler<std::chrono::nanoseconds>("euler_2", euler_2, 4'000'000);
    time_euler<std::chrono::microseconds>("euler_3", euler_3, 600851475143);
    time_euler<std::chrono::microseconds>("euler_4", euler_4, 3);
    
    return 0;
}
