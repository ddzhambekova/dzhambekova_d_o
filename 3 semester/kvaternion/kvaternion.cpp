#include "kvaternion.h"

bool Kvaternion::operator==(const Kvaternion& k)
{
    return ((a == k.a) && (b == k.b) && (c == k.c) && (d == k.d));
}

Kvaternion Kvaternion::operator+=(const Kvaternion& k)
{
    a += k.a;
    b += k.b;
    c += k.c;
    d += k.d;
    return *this;
}

Kvaternion operator+(const Kvaternion& k, const Kvaternion& l)
{
    Kvaternion r(k);
    return (r += l);
}

Kvaternion Kvaternion::operator-=(const Kvaternion& k)
{
    a -= k.a;
    b -= k.b;
    c -= k.c;
    d -= k.d;
    return *this;
}

Kvaternion operator-(const Kvaternion& k, const Kvaternion& l)
{
    Kvaternion r(k);
    return (r -= l);
}

Kvaternion Kvaternion::operator*=(const double q)
{
    a *= q;
    b *= q;
    c *= q;
    d *= q;
    return *this;
}

Kvaternion operator*(const Kvaternion& k, const double q)
{
    Kvaternion r(k);
    return(r *= q);
}

Kvaternion operator*(const double q, const Kvaternion& k)
{
    Kvaternion r(k);
    return(r *= q);
}

Kvaternion Kvaternion::operator*=(const Kvaternion& k)
{
    Kvaternion r(a*k.a + b*k.c, a*k.b + b*k.d, c*k.a + d*k.c, c*k.b + d*k.d);
    a = r.a;
    b = r.b;
    c = r.c;
    d = r.d;
    return *this;
}

Kvaternion operator*(const Kvaternion& k, const Kvaternion& l)
{
    Kvaternion r(k);
    return(r *= l);
}

Kvaternion Kvaternion::operator/=(const double q)
{
    a /= q;
    b /= q;
    c /= q;
    d /= q;
    return *this;
}

Kvaternion operator/(const Kvaternion& k, const double q)
{
    Kvaternion r(k);
    return(r /= q);
}

double Kvaternion::determ()
{
    return(a * d - b * c);
}

Kvaternion Kvaternion::transp()
{
    double t(c);
    c = b;
    b = t;
    return *this;
}

Kvaternion Kvaternion::inverse()
{
    Kvaternion r(a, b, c, d);
    double det = r.determ();
    Kvaternion dop(d, -c, -b, a);
    r = dop.transp();
    r /= det;
    a = r.a;
    b = r.b;
    c = r.c;
    d = r.d;
    return *this;
}

std::ostream& Kvaternion::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << a << separator << b << separator << c << separator << d << rightBrace;
    return ostrm;
}
std::istream& Kvaternion::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    char sep(0);
    char rightBrace(0);
    double a_(0.0);
    double b_(0.0);
    double c_(0.0);
    double d_(0.0);
    istrm >> leftBrace >> a >> sep >> b >> sep >> c >> sep >> d >> rightBrace;
    if (istrm.good())
    {
        if ((Kvaternion::leftBrace == leftBrace) && (Kvaternion::separator == sep)
            && (Kvaternion::rightBrace == rightBrace))
        {
            a = a_;
            b = b_;
            c = c_;
            d = d_;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}