#include "euler4.hpp"
#include <iostream>


// returns number of digits a number has in a base
int64_t number_of_digits_in_base(int64_t number, int64_t base) {
    int d = 1;
    if (number < 0) {
        number = number * -1;
    }

    while (number >= base) {
        ++d;
        number /= base;
    }
    return d;
}

// gives the element in the base ^ index place
// eg, to get the ones digit of the number 111 in base 10, pass (111,0,10)
// if the number doesn't have that many digits, it will return a 0, which makes sense if you ponder
int64_t extract_digit(int64_t number, int64_t index, int64_t base) {
    int64_t right_side_modulo = 1;

    while (index > 0) {
       --index;
       right_side_modulo *= base;
    }
    
    auto left_side_modulo = right_side_modulo * base;

    // eg if the number is 1234, and you want the digit in index 2
    // it's gonna do 234 / 100 = 2
    return (number % left_side_modulo) / right_side_modulo;
}

bool is_palindrome(int64_t number, int64_t base) {
    int digits = number_of_digits_in_base(number, base);

    for (int index = 0; index < (digits / 2); ++index) {
        if (extract_digit(number, index, base) != extract_digit(number, digits - index - 1, base)) {
            return false;
        }
    }

    return true;
}


// gemini suggested optimization after it read the code I wrote
// I tested it and it's only very slightly faster even with seven digit numbers, so I'll use mine
bool is_palindrome_fast(int64_t number, int64_t base) {
    if (number < 0) return false; // Palindromes are usually defined as positive
    if (number < base) return true; // Single digits are always palindromes

    int64_t original = number;
    int64_t reversed = 0;

    while (number > 0) {
        reversed = reversed * base + (number % base);
        number /= base;
    }

    return original == reversed;
}

int64_t euler_4(int64_t digits) {
    auto base = 10;

    int64_t min_digits_number = 1;
    for (int i = 0; i < (digits-1); ++i) {
        min_digits_number *= base;
    }
    int64_t max_digits_number = min_digits_number * base - 1;

    int64_t max_palindrome = 0;
    for (int64_t left_number = max_digits_number; left_number >= min_digits_number; --left_number) {
        if (left_number * left_number < max_palindrome) {
            break;
        }
       
        for (int64_t right_number = left_number; right_number >= min_digits_number; --right_number) {
            auto product = left_number * right_number;
            if (product < max_palindrome) {
                break;
            }
            if (is_palindrome(product, base)) {
                max_palindrome = product;
            }
        }

    }
    return max_palindrome;
}