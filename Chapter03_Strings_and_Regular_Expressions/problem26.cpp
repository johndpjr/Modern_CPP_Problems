/*
 * 26. Joining strings together separated by a delimiter
 * Given a list of strings, concatenate them seperated by a delimiter.
 * The delimiter should not appear after the last string.
 */
#include <iostream>
#include <string>
#include <vector>

std::string join_strings(const std::vector<std::string>& str_vec,
                         const char& delimiter);

int main() {
    std::vector<std::string> vec { "this","is","an","example" };
    std::cout << join_strings(vec, ',') << std::endl;

    std::vector<std::string> vec1;
    std::cout << join_strings(vec1, ' ') << std::endl;

    return 0;
}

std::string join_strings(const std::vector<std::string>& str_vec,
                         const char& delimiter) {
    if (str_vec.empty())
        return "";

    std::string concat_str;
    for (size_t i{0}; i<str_vec.size()-1; ++i) {
        concat_str += str_vec.at(i) + delimiter;
    }

    // The delimiter shouldn't appear after the last string
    concat_str += str_vec.at(str_vec.size()-1);
    return concat_str;
}