/*
 * 22. Literals of various temperature scales
 * Write a library that represents 3 temperatures: Celsius, Fahrenheit, and Kelvin.
 * Support conversion between temperatures.
 */

#include <iostream>
#include <sstream>

struct Temperature {
public:
    enum Scale {
        Celsius,
        Fahrenheit,
        Kelvin
    };

private:
    friend Temperature operator"" _deg(long double val);
    friend Temperature operator"" _f(long double val);
    friend Temperature operator"" _K(long double val);

    long double mCelsius;
    Scale mPreferredScale;

    long double getCelsius() const     { return mCelsius; }
    long double getFahrenheit() const  { return (9.f/5.f * mCelsius + 32); }
    long double getKelvin() const      { return (mCelsius + 273.15); }

public:
    Temperature()
        : mCelsius{0}, mPreferredScale{Scale::Celsius} {}
    explicit Temperature(long double val)
        : mCelsius{val}, mPreferredScale{Scale::Celsius} {}
    Temperature(long double val, Scale scale)
        : mCelsius{val}, mPreferredScale{scale} {}

    // Returns the value of the temperature in the preferred scale
    long double get() const;
    // Returns the value of the temperature in the given scale
    long double get(Scale scale) const;

    Scale getPreferredScale() const      { return mPreferredScale; }
    void setPreferredScale(Scale scale)  { mPreferredScale = scale; }

    Temperature& operator=(const Temperature& t) {
        mCelsius = t.getCelsius();
        mPreferredScale = t.getPreferredScale();
        return *this;
    }

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

    friend bool operator==(const Temperature& lhs, const Temperature& rhs) {
        return lhs.getCelsius() == rhs.getCelsius();
    }

    friend bool operator<(const Temperature& lhs, const Temperature& rhs) {
        return lhs.getCelsius() < rhs.getCelsius();
    }

    friend bool operator>(const Temperature& lhs, const Temperature& rhs) {
        return lhs.getCelsius() > rhs.getCelsius();
    }

    friend bool operator<=(const Temperature& lhs, const Temperature& rhs) {
        return lhs.getCelsius() <= rhs.getCelsius();
    }

    friend bool operator>=(const Temperature& lhs, const Temperature& rhs) {
        return lhs.getCelsius() >= rhs.getCelsius();
    }

    friend std::ostream& operator<<(std::ostream& os, const Temperature& t) {
        os << t.get();
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Temperature& t) {
        long double val;
        is >> val;
        // The preferred temperature scale will default to Celsius
        t = Temperature(val);
        return is;
    }
};

Temperature operator"" _deg(long double val) {
    return Temperature(val, Temperature::Scale::Celsius);
}
Temperature operator"" _f(long double val) {
    return Temperature((5.f/9.f * (val - 32)), Temperature::Scale::Fahrenheit);
}
Temperature operator"" _K(long double val) {
    return Temperature(val - 273.15, Temperature::Scale::Kelvin);
}

long double Temperature::get() const {
    return get(mPreferredScale);
}

long double Temperature::get(Scale scale) const {
    switch (scale) {
        case Temperature::Scale::Celsius:     return getCelsius();
        case Temperature::Scale::Fahrenheit:  return getFahrenheit();
        case Temperature::Scale::Kelvin:      return getKelvin();
    }
}


int main() {
    Temperature temp{100.0_f};
    Temperature temp1;
    temp1 = temp;
    Temperature::Scale scale{temp1.getPreferredScale()};

    std::cout << scale << std::endl;
}