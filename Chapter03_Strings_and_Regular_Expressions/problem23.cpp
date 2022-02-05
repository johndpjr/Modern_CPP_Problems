/*
 * 23. Binary to string conversion
 * Convert a range of 8-bit integers to a string containing a hexadecimal representation.
 * The function should allow upper or lower case output.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

std::string get_hex_str_from_bit_range(const std::vector<unsigned char>& vec,
                                       bool lowercase = true);

int main() {
    std::vector<unsigned char> vec { 0xBA, 0xAD, 0xF0, 0x0D };
    std::cout << get_hex_str_from_bit_range(vec) << std::endl;

    std::vector<unsigned char> vec1 { 0xDE, 0xAD, 0xBE, 0xEF };
    std::cout << get_hex_str_from_bit_range(vec1, false) << std::endl;

    std::vector<unsigned char> vec2 { 1,2,3,4,5,6 };
    std::cout << get_hex_str_from_bit_range(vec2) << std::endl;

    return 0;
}

std::string get_hex_str_from_bit_range(const std::vector<unsigned char>& vec, bool lowercase) {
    std::stringstream ss;
    if (!lowercase)
        ss << std::uppercase;
    ss << std::hex << std::setfill('0');

    for (const auto& val: vec)
        ss << std::setw(2) << static_cast<unsigned short>(val);

    return ss.str();
}