#include "rational.h"
#include <iostream>
#include <sstream>

int nod(int& a, int& b)
{
    if (a == 0 || b == 0)
    {
        if (abs(a) > abs(b))
        {
            return a;
        }
        else return b;
    }
    int a1 = a;
    int b1 = b;
    if (abs(a1) > abs(b1))
    {
        int t = a1;
        a1 = b1;
        b1 = t;
    }
    while (a1 % b1 != 0)
    {
        a1 = a1 % b1;
        int t = a1;
        a1 = b1;
        b1 = t;
    }
    return abs(b1);
}

void Rational::normalize(Rational& s)
{
    int k = nod(s.num_, s.denum_);
    s = Rational(s.num_ / k, s.denum_ / k);
    if (s.denum_ < 0)
    {
        s.denum_ *= -1;
        s.num_ *= -1;
    }
}

Rational& Rational::operator^(const int k)
{
    Rational res;
    res.num_ = pow(num_, k);
    res.denum_ = pow(denum_, k);
    normalize(res);
    return res;
}

Rational& Rational::operator+=(const Rational& rhs)
{
    num_ = num_ * rhs.denum_ + rhs.num_ * denum_;
    denum_ *= rhs.denum_;
    normalize(*this);
    return *this;
}

Rational& Rational::operator+=(const double rhs)
{
    double a(rhs);
    double cel;
    int den = 1;
    double j = modf(a, &cel);
    while (j < 1 && j != 0)
    {
        a *= 10;
        den *= 10;
        j = modf(a, &cel);
    }
    Rational b = Rational(a, den);
    num_ = num_ * den + a * denum_;
    denum_ = denum_ * den;
    normalize(*this);
    return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs)
{
    Rational sum(lhs);
    sum += rhs;
    return sum;
}

Rational& Rational::operator-=(const Rational& rhs)
{
    num_ = num_ * rhs.denum_ - rhs.num_ * denum_;
    denum_ *= rhs.denum_;
    normalize(*this);
    return *this;
}

Rational operator-(const Rational& lhs, const Rational& rhs)
{
    Rational raz(lhs);
    raz -= rhs;
    return raz;
}

Rational& Rational::operator-=(const double rhs)
{
    double a(rhs);
    double cel;
    int den = 1;
    double j = modf(a, &cel);
    while (j < 1 && j != 0)
    {
        a *= 10;
        den *= 10;
        j = modf(a, &cel);
    }
    Rational b = Rational(a, den);
    num_ = num_ * den - a * denum_;
    denum_ = denum_ * den;
    normalize(*this);
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
    num_ *= rhs.num_;
    denum_ *= rhs.denum_;
    normalize(*this);
    return *this;
}

Rational operator*(const Rational& lhs, const Rational& rhs)
{
    Rational mul(lhs);
    mul *= rhs;
    return mul;
}

Rational& Rational::operator*=(const double rhs)
{
    double a(rhs);
    double cel;
    int den = 1;
    double j = modf(a, &cel);
    while (j < 1 && j != 0)
    {
        a *= 10;
        den *= 10;
        j = modf(a, &cel);
    }
    Rational b = Rational(a, den);
    num_ = num_ * a;
    denum_ = denum_ * den;
    normalize(*this);
    return *this;
}

Rational& Rational::operator/=(const Rational& rhs)
{
    num_ *= rhs.denum_;
    denum_ *= rhs.num_;
    normalize(*this);
    return *this;
}

Rational operator/(const Rational& lhs, const Rational& rhs)
{
    Rational del(lhs);
    del /= rhs;
    return del;
}

Rational& Rational::operator/=(const double rhs)
{
    double a(rhs);
    double cel;
    int den = 1;
    double j = modf(a, &cel);
    while (j < 1 && j != 0)
    {
        a *= 10;
        den *= 10;
        j = modf(a, &cel);
    }
    Rational b = Rational(a, den);
    num_ = num_ * den;
    denum_ = denum_ * a;
    normalize(*this);
    return *this;
}

bool Rational::operator>(const Rational& rhs)
{
    bool t = num_ * rhs.denum_ > denum_ * rhs.num_;
    return t;
}

bool Rational::operator==(const Rational& rhs)
{
    bool t = num_ * rhs.denum_ == denum_ * rhs.num_;
    return t;
}


std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << num_ << separator << denum_ << rightBrace;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    int num(0);
    char sep(0);
    int denum(0);
    char rightBrace(0);
    istrm >> leftBrace >> num >> sep >> denum >> rightBrace;
    if (istrm.good())
    {
        if ((Rational::leftBrace == leftBrace) && (Rational::separator == sep)
            && (Rational::rightBrace == rightBrace))
        {
            num_ = num;
            denum_ = denum;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}