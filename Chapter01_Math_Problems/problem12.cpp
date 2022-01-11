/*
 * 12. Largest Collatz sequence
 * Print a number under 1 million that produces the longest Collatz sequence.
 */

#include <iostream>

unsigned getCollatzLength(unsigned long number) {
    unsigned length{0};

    while (number != 1) {
        if (!(number % 2)) {
            number /= 2;
        }
        else {
            number = 3*number + 1;
        }
        ++length;
    }
    return length;
}

int main() {
    unsigned longestCollatzLength{0};
    unsigned longestCollatzNumber{0};
    for (int i{2}; i<=1'000'000; ++i) {
        unsigned collatzLength{getCollatzLength(i)};
        if (collatzLength > longestCollatzLength) {
            longestCollatzLength = collatzLength;
            longestCollatzNumber = i;
        }
    }

    std::cout << "The number under 1 million that produces the longest Collatz sequence is "
              << longestCollatzNumber << " with a length of " << longestCollatzLength << std::endl;
}