#include "vec3d.h"

#include <iostream>
#include <sstream>

bool Vec3d::operator==(const Vec3d& rhs)
{
    return ((x_ == rhs.x_) && (y_ == rhs.y_) && (z_ == rhs.z_));
}

Vec3d Vec3d::operator+=(const Vec3d& rhs)
{
    x_ += rhs.x_;
    y_ += rhs.y_;
    z_ += rhs.z_;
    return *this;
}

Vec3d operator+(const Vec3d& rhs, const Vec3d& lhs)
{
    Vec3d sum(rhs);
    sum += lhs;
    return sum;
}

Vec3d Vec3d::operator-=(const Vec3d& rhs)
{
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    z_ -= rhs.z_;
    return *this;
}

Vec3d operator-(const Vec3d& rhs, const Vec3d& lhs)
{
    Vec3d dif(rhs);
    dif -= lhs;
    return dif;
}

Vec3d Vec3d::operator*=(const double d)
{
    x_ *= d;
    y_ *= d;
    z_ *= d;
    return *this;
}

Vec3d operator*(const Vec3d rhs, const double d)
{
    Vec3d u(rhs);
    u *= d;
    return u;
}

Vec3d Vec3d::operator/=(const double d)
{
    x_ /= d;
    y_ /= d;
    z_ /= d;
    return *this;
}

Vec3d operator/(const Vec3d& rhs, const double d)
{
    Vec3d r(rhs);
    r /= d;
    return r;
}

double Vec3d::module()
{
    return double(sqrt(x_ * x_ + y_ * y_ + z_ * z_));
}

double Vec3d::skalpr(const Vec3d& rhs)
{
    return double(x_ * rhs.x_ + y_ * rhs.y_ + z_ * rhs.z_);
}

Vec3d Vec3d::vectpr(const Vec3d& rhs)
{
    Vec3d res;
    res.x_ = y_ * rhs.z_ - z_ * rhs.y_;
    res.y_ = z_ * rhs.x_ - x_ * rhs.z_;
    res.z_ = x_ * rhs.y_ - y_ * rhs.x_;
    return res;
}

double Vec3d::angle(const Vec3d& rhs)
{
    Vec3d v1(x_, y_, z_);
    Vec3d v2(rhs);
    double s(v1.skalpr(v2));
    double m1(v1.module());
    double m2(v2.module());
    double cos(s / (m1 * m2));
    return acos(cos);
}

std::ostream& Vec3d::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x_ << separator << y_ << separator << z_ << rightBrace;
    return ostrm;
}
std::istream& Vec3d::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double x(0.0);
    char sep(0);
    double y(0.0);
    double z(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> x_ >> sep >> y_ >> sep >> z_ >> rightBrace;
    if (istrm.good())
    {
        if ((Vec3d::leftBrace == leftBrace) && (Vec3d::separator == sep)
            && (Vec3d::rightBrace == rightBrace))
        {
            x_ = x;
            y_ = y;
            z_ = z;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}