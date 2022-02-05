/*
 * 24. String to binary conversion
 * Return a hex_digitstor of 8-bit integers given a hex string.
 * The function should be case-insensitive on input.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

std::vector<unsigned char> get_bit_range_from_hex_str(const std::string& hex_str);
void print_vec(std::vector<unsigned char> vec);

int main() {
    std::string hex_str {"baadF00D" };
    print_vec(get_bit_range_from_hex_str(hex_str));

    std::string hex_str1 { "DEADBEEF" };
    print_vec(get_bit_range_from_hex_str(hex_str1));

    std::string hex_str2 { "010203040506" };
    print_vec(get_bit_range_from_hex_str(hex_str2));

    return 0;
}

std::vector<unsigned char> get_bit_range_from_hex_str(const std::string& hex_str) {
    std::vector<unsigned char> bit_range;
    for (size_t i{0}; i<hex_str.length()-1; i+=2) {
        auto num {std::stoi(hex_str.substr(i, 2), nullptr, 16)};
        bit_range.push_back(static_cast<unsigned char>(num));
    }

    return bit_range;
}

void print_vec(std::vector<unsigned char> vec) {
    for (const auto& v: vec) {
        std::cout << static_cast<int>(v) << ' ';
    }
    std::cout << std::endl;
}