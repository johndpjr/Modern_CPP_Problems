/*
 * 25. Capitalizing an article title
 * Write a function that converts a string to title case.
 */
#include <iostream>
#include <string>
#include <sstream>

const std::string LOWER_ALPHABET {"abcdefghijklmnopqrstuvwxyz"};
const std::string UPPER_ALPHABET {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
const size_t ALPHABET_SIZE {26};

std::string to_title_case(const std::string& str);

int main() {
    std::string s {"the c++ challenger"};
    std::cout << to_title_case(s) << std::endl;

    return 0;
}

std::string to_title_case(const std::string& str) {
    std::stringstream ss {str};
    std::stringstream new_str;

    std::string word;
    while (ss >> word) {
        size_t alphabet_index {LOWER_ALPHABET.find(word.at(0))};
        // Capitalize first letter of the word if it's in LOWER_ALPHABET
        if (alphabet_index != std::string::npos) {
            new_str << UPPER_ALPHABET.at(alphabet_index) << word.substr(1, word.size()-1) << ' ';
        }
    }

    return new_str.str();
}
