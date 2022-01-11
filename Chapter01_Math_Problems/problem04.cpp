/*
 * 4. Largest prime smaller than given number
 * Calculate the largest prime number smaller than a given number.
 */

#include <iostream>
#include <cmath>

bool isPrime(const unsigned long& num);

int main() {
    int number;
    std::cout << "Enter a positive integer: ";
    std::cin >> number;

    if (number <= 0) {
        std::cout << "The number must be a positive integer";
    }
    else {
        // The start number must be at least one less than the number
        // and it should be odd (no need to check even nums)
        int start{number-1};
        if (start % 2 == 0)
            --start;

        for (int i{start}; i > 1; i -= 2) {
            if (isPrime(i)) {
                std::cout << i << " is the largest prime number smaller than " << number << std::endl;
                break;
            }
        }
    }
}

bool isPrime(const unsigned long& num) {
    if (num <= 1 || num % 2 == 0) {
        return false;
    }

    for (unsigned long i{3}; i<(unsigned long)sqrt(num); i+=2) {
        if (num % i == 0)
            return false;
    }

    return true;
}