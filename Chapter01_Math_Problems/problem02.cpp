/*
 * 2. Greatest common divisor
 * Compute the greatest common divisor given two positive integers.
 */

#include <iostream>

int main() {
    int num1, num2;
    std::cout << "Enter two integers seperated by a space: ";
    std::cin >> num1 >> num2;

    int smallestNum;
    int largestNum;
    if (num1 < num2) {
        smallestNum = num1;
        largestNum = num2;
    }
    else {
        smallestNum = num2;
        largestNum = num1;
    }

    int divisor{smallestNum};
    int greatestCommonDivisor{1};
    while (divisor != 1) {
        if (largestNum % divisor == 0) {
            greatestCommonDivisor = divisor;
        }
        --divisor;
    }

    std::cout << "GCD: " << greatestCommonDivisor << std::endl;
}