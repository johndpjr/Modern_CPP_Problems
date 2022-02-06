/*
 * 27. Splitting a string into tokens with a list of possible delimiters
 * Given a string and possible delimiters, return a vector containing the tokens seperated
 * by the delimiters.
 */
#include <iostream>
#include <string>
#include <vector>

using std::string;

std::vector<string> get_str_tokens(const string& str, const string& delimiters);

int main() {
    string str {"!this,is.a sample!!" };
    std::vector<string> str_tokens {get_str_tokens(str, ",.! ")};
    for (const auto& val: str_tokens) {
        std::cout << val << ' ';
    }

    return 0;
}

std::vector<string> get_str_tokens(const string& str, const string& delimiters) {
    size_t token_start {0};
    std::vector<string> str_vec;
    for (size_t token_end{0}; token_end<str.size(); ++token_end) {
        if (delimiters.find(str.at(token_end)) != string::npos) {
            str_vec.push_back(str.substr(token_start, (token_end-token_start)));
            token_start = token_end+1;
        }
    }

    return str_vec;
}