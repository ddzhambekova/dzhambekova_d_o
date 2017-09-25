#ifndef RATIONAL_H_20170921
#define RATIONAL_H_20170921
#include <iosfwd>
#include <iostream>

class Rational
{
public:
    Rational() = default;
    Rational(const int num) : num_(num) {}
    Rational::Rational(const int num, const int denum) : num_(num), denum_(denum)
    {
        if (denum == 0)
        {
            throw std::invalid_argument("Error!");
        }
    }

    void Normalize(Rational& s);
    ~Rational() = default;
    bool operator==(const Rational& rhs) const { return (num_ == rhs.num_) && (denum_ == rhs.denum_); }
    bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);

    static const char leftBrace{ '{' };
    static const char separator{ '/' };
    static const char rightBrace{ '}' };

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
    int num_{ 0 };
    int denum_{ 1 };
};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
    return rhs.readFrom(istrm);
}

#endif