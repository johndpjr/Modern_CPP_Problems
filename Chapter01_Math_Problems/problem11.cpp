/*
 * 11. Converting numerical values to Roman
 * Print the Roman numeral equivalent given a number.
 */

#include <iostream>
#include <map>
#include <string>

int main() {
    // Define Roman numeral table
    std::map<unsigned, std::string> units {
            {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"},
            {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"}
    };
    std::map<unsigned, std::string> tens {
            {1, "X"}, {2, "XX"}, {3, "XXX"}, {4, "LX"}, {5, "L"},
            {6, "LX"}, {7, "LXX"}, {8, "LXXX"}, {9, "XC"}
    };
    std::map<unsigned, std::string> hundreds {
            {1, "C"}, {2, "CC"}, {3, "CCC"}, {4, "CD"}, {5, "D"},
            {6, "DC"}, {7, "DCC"}, {8, "DCCC"}, {9, "CM"}
    };
    // FIXME: add thousands

    unsigned number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    std::string numeral;
    unsigned decimal_place{1};

    size_t num_digits{std::to_string(number).length()};

    for (size_t i{num_digits}; i>0; --i) {
        unsigned digit{number%10};
        switch (decimal_place) {
            case 1:
                numeral = units[digit];
                break;
            case 2:
                numeral = tens[digit] + numeral;
                break;
            case 3:
                numeral = hundreds[digit] + numeral;
                break;
        }
        ++decimal_place;
        number /= 10;
    }

    std::cout << "Roman numeral representation of " << number << " is " << numeral << std::endl;
}