#ifndef VEC3DT_H_20171011
#define VEC3DT_H_20171011

#include <iostream>

template<typename T>
struct Vec3dt
{
public:
    Vec3dt<T>() = default;
    Vec3dt<T>(const T x, const T y, const T z) : x_(x), y_(y), z_(z)
    {
    }
    ~Vec3dt<T>() = default;
    Vec3dt(const Vec3dt<T>& v) : x_(v.x_), y_(v.y_), z_(v.z_)
    {
    }
    Vec3dt operator=(const Vec3dt<T>& v)
    {
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
        return *this;
    }
    //bool operator==(const Vec3dt<T>& rhs);
    //bool operator!=(const Vec3dt<T>& rhs) { return !operator==(rhs); }

    //Vec3dt operator+=(const Vec3dt<T>& rhs);
    //Vec3dt operator-=(const Vec3dt<T>& rhs);

    //Vec3dt operator*=(const T d);
    //Vec3dt operator/=(const T d);

    //double module();
    //double skalpr(const Vec3dt<T>& rhs);
    //Vec3dt vectpr(const Vec3dt<T>& rhs);
    //double angle(const Vec3dt<T>& rhs);

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

public:
    T x_{ 0 };
    T y_{ 0 };
    T z_{ 0 };
};

template<typename T>
inline std::ostream& operator<<(std::ostream& ostrm, const Vec3dt<T>& rhs)
{
    return rhs.writeTo(ostrm);
}
template<typename T>
inline std::istream& operator >> (std::istream& istrm, Vec3dt<T>& rhs)
{
    return rhs.readFrom(istrm);
}

//template<typename T>
//bool Vec3dt<T>::operator==(const Vec3dt& rhs)
//{
//    return ((x_ == rhs.x_) && (y_ == rhs.y_) && (z_ == rhs.z_));
//}
//
//template<typename T>
//Vec3dt<T> Vec3dt<T>::operator+=(const Vec3dt& rhs)
//{
//    x_ += rhs.x_;
//    y_ += rhs.y_;
//    z_ += rhs.z_;
//    return *this;
//}
//
//template<typename T>
//Vec3dt<T> operator+(const Vec3dt& rhs, const Vec3dt& lhs)
//{
//    Vec3dt sum(rhs);
//    sum += lhs;
//    return sum;
//}
//
//template<typename T>
//Vec3dt<T> Vec3dt<T>::operator-=(const Vec3dt& rhs)
//{
//    x_ -= rhs.x_;
//    y_ -= rhs.y_;
//    z_ -= rhs.z_;
//    return *this;
//}
//
//template<typename T>
//Vec3dt<T> operator-(const Vec3dt& rhs, const Vec3dt& lhs)
//{
//    Vec3dt dif(rhs);
//    dif -= lhs;
//    return dif;
//}
//
//template<typename T>
//Vec3dt<T> Vec3dt<T>::operator*=(const T d)
//{
//    x_ *= d;
//    y_ *= d;
//    z_ *= d;
//    return *this;
//}
//
//template<typename T>
//Vec3dt<T> operator*(const Vec3dt rhs, const T d)
//{
//    Vec3dt u(rhs);
//    u *= d;
//    return u;
//}
//
//template<typename T>
//Vec3dt<T> Vec3dt<T>::operator/=(const T d)
//{
//    x_ /= d;
//    y_ /= d;
//    z_ /= d;
//    return *this;
//}
//
//template<typename T>
//Vec3dt<T> operator/(const Vec3dt& rhs, const T d)
//{
//    Vec3dt r(rhs);
//    r /= d;
//    return r;
//}
//
//template<typename T>
//double Vec3dt<T>::module()
//{
//    return double(sqrt(x_ * x_ + y_ * y_ + z_ * z_));
//}
//
//template<typename T>
//double Vec3dt<T>::skalpr(const Vec3dt& rhs)
//{
//    return double(x_ * rhs.x_ + y_ * rhs.y_ + z_ * rhs.z_);
//}
//
//template<typename T>
//Vec3dt<T> Vec3dt<T>::vectpr(const Vec3dt& rhs)
//{
//    Vec3d res;
//    res.x_ = y_ * rhs.z_ - z_ * rhs.y_;
//    res.y_ = z_ * rhs.x_ - x_ * rhs.z_;
//    res.z_ = x_ * rhs.y_ - y_ * rhs.x_;
//    return res;
//}
//
//template<typename T>
//double Vec3dt<T>::angle(const Vec3dt& rhs)
//{
//    Vec3dt v1(x_, y_, z_);
//    Vec3dt v2(rhs);
//    double s(v1.skalpr(v2));
//    double m1(v1.module());
//    double m2(v2.module());
//    double cos(s / (m1 * m2));
//    return acos(cos);
//}

template<typename T>
std::ostream& Vec3dt<T>::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << x_ << separator << y_ << separator << z_ << rightBrace;
    return ostrm;
}
template<typename T>
std::istream& Vec3dt<T>::readFrom(std::istream& istrm)
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
        if ((Vec3dt<T>::leftBrace == leftBrace) && (Vec3dt<T>::separator == sep)
            && (Vec3dt<T>::rightBrace == rightBrace))
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

#endif