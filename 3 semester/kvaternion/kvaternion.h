#ifndef KVATERNION_H_20171019
#define KVATERNION_H_20171019

#include<iostream>

struct Kvaternion
{
public:
    Kvaternion() = default;
    ~Kvaternion() = default;
    Kvaternion::Kvaternion(const double a_, const double b_, const double c_, const double d_) : a(a_), b(b_), c(c_), d(d_)
    {
    }
    Kvaternion(const Kvaternion& k) : a(k.a), b(k.b), c(k.c), d(k.d)
    {
    }
    Kvaternion operator=(const Kvaternion& k)
    {
        a = k.a;
        b = k.b;
        c = k.c;
        d = k.d;
        return *this;
    }

    bool operator==(const Kvaternion& k);
    bool operator!=(const Kvaternion& k) { return !operator==(k); }

    Kvaternion operator+=(const Kvaternion& k);
    Kvaternion operator-=(const Kvaternion& k);
    Kvaternion operator*=(const double q);
    Kvaternion operator/=(const double q);
    Kvaternion operator*=(const Kvaternion& k);

    double determ();
    Kvaternion transp();
    Kvaternion inverse();

    static const char leftBrace{ '[' };
    static const char separator{ ',' };
    static const char rightBrace{ ']' };

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

public:
    double a{ 0.0 };
    double b{ 0.0 };
    double c{ 0.0 };
    double d{ 0.0 };
};
Kvaternion operator+(const Kvaternion& k, const Kvaternion& l);
Kvaternion operator-(const Kvaternion& k, const Kvaternion& l);
Kvaternion operator*(const Kvaternion& k, const double q);
Kvaternion operator/(const Kvaternion& k, const double q);
Kvaternion operator*(const double q, const Kvaternion& k);
Kvaternion operator*(const Kvaternion& k, const Kvaternion& l);

inline std::ostream& operator<<(std::ostream& ostrm, const Kvaternion& rhs)
{
    return rhs.writeTo(ostrm);
}
inline std::istream& operator >> (std::istream& istrm, Kvaternion& rhs)
{
    return rhs.readFrom(istrm);
}

#endif