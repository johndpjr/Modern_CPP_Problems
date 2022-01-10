/*
 * 9. Prime factors of a number
 * Print the prime factors of a number entered by the user.
 */

#include <iostream>
#include <math.h>

bool isPrime(const unsigned long& num);
bool isFactor(const unsigned long& num, const unsigned long& purported_factor);

int main() {
    unsigned long long number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    // The only even prime number is 2, so check it now
    // To avoid checking all even numbers
    if (isFactor(number, 2))
        std::cout << 2 << ' ';
    // Print the prime factors
    // FIXME: use the sieve thing
    for (unsigned long i{1}; i<=(unsigned long)number/2; i+=2) {
        if (isPrime(i) && isFactor(number, i)) {
            std::cout << i << ' ';
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

bool isFactor(const unsigned long& num, const unsigned long& purported_factor) {
    if (num % purported_factor == 0)
        return true;
    return false;
}