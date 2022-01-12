/*
 * 15. IPv4 data type
 * Write a class that represents an IPv4 address.
 */

#include <array>
#include <iostream>
#include <string>
#include <sstream>

class IPv4 {
private:
    std::array<unsigned char, 4> mData;

public:
    IPv4()
        : mData{0} {
    }
    IPv4(unsigned char const a, unsigned char const b,
         unsigned char const c, unsigned char const d)
         : mData{ {a, b, c, d} } {
    }
    IPv4& operator=(IPv4 const & other) {
        mData = other.mData;
        return *this;
    }

    std::string toString() const {
        std::stringstream ss;
        ss << *this;
        return ss.str();
    }

    friend std::ostream& operator<<(std::ostream& os, const IPv4& a) {
        os << static_cast<int>(a.mData[0]) << '.'
           << static_cast<int>(a.mData[1]) << '.'
           << static_cast<int>(a.mData[2]) << '.'
           << static_cast<int>(a.mData[3]);
        return os;
    }

    friend std::istream& operator>>(std::istream& is, IPv4& a) {
        char d1, d2, d3;
        int p1, p2, p3, p4;
        is >> p1 >> d1 >> p2 >> d2 >> p3 >> d3 >> p4;
        if (d1 == '.' && d2 == '.' && d3 == '.') {
            a = IPv4(p1, p2, p3, p4);
        }
        else {
            is.setstate(std::ios::failbit);
        }

        return is;
    }

    std::string getNetworkPart() const {
        std::stringstream ss;
        ss << static_cast<int>(mData[0]) << '.' << static_cast<int>(mData[1]);
        return ss.str();
    }

    std::string getHostPart() const {
        std::stringstream ss;
        ss << static_cast<int>(mData[2]) << '.' << static_cast<int>(mData[3]);
        return ss.str();
    }
};

int main() {
    // Overloaded << operator
    IPv4 a{168, 192, 0, 1};
    std::cout << a << std::endl;

    // Overloaded = operator
    IPv4 b;
    b = a;

    // Overloaded >> operator
    IPv4 c;
    std::cout << "Enter an IPv4 address with dots: ";
    std::cin >> c;

    // Get parts of the address
    std::cout << c.toString() << std::endl;
    std::cout << c.getNetworkPart() << std::endl;
    std::cout << c.getHostPart() << std::endl;
}