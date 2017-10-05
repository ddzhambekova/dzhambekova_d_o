#ifndef VEC3D_H_20171005
#define VEC3D_H_20171005

#include <iostream>

struct Vec3d
{
public:
    Vec3d() = default;
    Vec3d::Vec3d(const double x, const double y, const double z) : x_(x), y_(y), z_(z)
    {
    }
    ~Vec3d() = default;
    Vec3d(const Vec3d& v) : x_(v.x_), y_(v.y_), z_(v.z_)
    {
    }
    Vec3d operator=(const Vec3d& v)
    {
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
        return *this;
    }
    bool operator==(const Vec3d& rhs);
    bool operator!=(const Vec3d& rhs) { return !operator==(rhs); }

    Vec3d operator+=(const Vec3d& rhs);
    Vec3d operator-=(const Vec3d& rhs);

    Vec3d operator*=(const double d);
    Vec3d operator/=(const double d);

    double module();
    double skalpr(const Vec3d& rhs);
    Vec3d vectpr(const Vec3d& rhs);
    double angle(const Vec3d& rhs);

    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

public:
    double x_{ 0.0 };
    double y_{ 0.0 };
    double z_{ 0.0 };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Vec3d& rhs)
{
    return rhs.writeTo(ostrm);
}
inline std::istream& operator >> (std::istream& istrm, Vec3d& rhs)
{
    return rhs.readFrom(istrm);
}

#endif