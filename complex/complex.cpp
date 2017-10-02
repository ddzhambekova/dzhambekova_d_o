#include "complex.h"
#include <iostream>

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);

Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{
}

Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex operator+(const double rhs, const Complex& lhs)
{
    Complex sum(lhs);
    sum += rhs;
    return sum;
}

Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex& Complex::operator*=(const double rhs)
{
    re *= rhs;
    im *= rhs;
    return *this;
}

Complex& Complex::operator*=(const Complex& rhs)
{
    double t(re);
    re = t * rhs.re - im * rhs.im;
    im = im * rhs.re + t * rhs.im;
    return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re * rhs.re - lhs.im * rhs.im, lhs.im * rhs.re + lhs.re * rhs.im);
}

Complex& Complex::operator/=(const double rhs)
{
    re /= rhs;
    im /= rhs;
    return *this;
}

Complex& Complex::operator/=(const Complex& rhs)
{
    double s(re);
    double b(im);
    re = (s * rhs.re + b * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    im = (b * rhs.re - s * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    return *this;
}

Complex operator/(const Complex& lhs, const Complex& rhs)
{
    Complex res;
    res.re = (lhs.re * rhs.re + lhs.im * rhs.im) / (lhs.im * lhs.im + rhs.im * rhs.im);
    res.im = (rhs.re * lhs.im - lhs.re * rhs. im) / (lhs.im * lhs.im + rhs.im * rhs.im);
    return res;
}

Complex& Complex::operator^(const int k)
{
    double z(sqrt(re * re + im * im));
    double f = atan(im / re);
    double m(pow(z, k));
    Complex res;
    res.re = m*cos(f * k);
    res.im = m*sin(f * k);
    return res;
}

//Complex sopr(const Complex& rhs)
//{
//    Complex q;
//    q.re = rhs.re;
//    q.im = -rhs.im;
//    return q;
//}

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaginary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
    if (istrm.good())
    {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace))
        {
            re = real;
            im = imaginary;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}