/*
 * 1. Sum of naturals divisible by 3 and 5
 * Calculate and print the sum of all natural numbers divisible by 3 or 5
 * up to the limit given by the user.
 */

#include <iostream>

int main() {
    // Get the upper limit
    int limit;
    std::cout << "Enter an upper limit: ";
    std::cin >> limit;

    unsigned long long sum{0};
    for (size_t i{3}; i<limit; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    std::cout << "The sum of all numbers divisible by 3 or 5 for the number " << limit << " is " << sum << std::endl;
}