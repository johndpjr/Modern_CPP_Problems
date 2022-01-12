/*
 * 22. Literals of various temperature scales
 * Write a library that represents 3 temperatures: Celsius, Fahrenheit, and Kelvin.
 * Support conversion between temperatures.
 */

#include <iostream>

struct Temperature {
private:
    friend Temperature operator"" _deg(long double val);
    friend Temperature operator"" _f(long double val);
    friend Temperature operator"" _K(long double val);

    long double mCelsius{0};
public:
    explicit Temperature(long double val)
        : mCelsius{val} {}

    long double getCelsius() const    { return mCelsius; }
    long double getFahrenheit() const { return (9.f/5.f * mCelsius + 32); }
    long double getKelvin() const     { return (mCelsius + 273.15); }

    Temperature operator+(Temperature other) {
        return Temperature(getCelsius() + other.getCelsius());
    }

    Temperature operator-(Temperature other) {
        return Temperature(getCelsius() - other.getCelsius());
    }

    Temperature operator*(long double multiplier) {
        return Temperature(getCelsius() * multiplier);
    }

    Temperature operator/(long double divisor) {
        return Temperature(getCelsius() / divisor);
    }
};

Temperature operator"" _deg(long double val) {
    return Temperature(val);
}
Temperature operator"" _f(long double val) {
    return Temperature(5.f/9.f * (val - 32));
}
Temperature operator"" _K(long double val) {
    return Temperature(val - 273.15);
}


int main() {
    Temperature temp{100.0_deg};
    Temperature temp2{50.0_deg};

    Temperature t1 = temp / 2;
    std::cout << "Celsius: " << t1.getCelsius()
              << "\nFahrenheit: " << t1.getFahrenheit()
              << "\nKelvin: " << t1.getKelvin()
              << std::endl;
}