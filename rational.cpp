#include <iostream>
#include <sstream>
using namespace std;

class Rational
{
public:
    Rational() = default;
    Rational(const int num) : num_(num) {}
    Rational::Rational(const int num, const int denum)
        : num_(num), denum_(denum)
    {
        if (0 == denum_)
        {
            cout << "Error!" << endl;
        }
        if (denum_ < 0)   //перенос минуса из знаменателя в числитель
        {
            denum_ *= -1;
            num_ *= -1;
        }
        
    }
    //int nod(int& num_, int& denum_) //алгоритм евклида - поиск НОД и сокращение дроби
    //{
    //    int t = 1;
    //    while (num_ != denum_)
    //    {
    //        if (num_ > denum_) t = num_ - denum_;
    //        else t = denum_ - num_;
    //        return t;
    //    }
    //    if (t != 1)
    //    {
    //        num_ /= t;
    //        denum_ /= t;
    //    }
    //}

    ~Rational() = default;
    bool operator==(const Rational& rhs) const { return (num_ == rhs.num_) && (denum_ == rhs.denum_); }
    bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);

    static const char leftBrace{ '{' };
    static const char separator{ '/' };
    static const char rightBrace{ '}' };
    
    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

private:
    int num_{ 0 };
    int denum_{ 1 };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Rational& rhs)
{
    return rhs.readFrom(istrm);
}

int main()
{
    Rational m(1, 3);
    cout << m << endl;
    m += Rational(1, 2);
    cout << m << endl;
    m -= Rational(1, 6);
    cout << m << endl;
    Rational er(1, 0);
    cout << er << endl;
    Rational d(2, -5);
    cout << d << endl;
}

Rational& Rational::operator+=(const Rational& rhs)
{
    num_ = num_ * rhs.denum_ + rhs.num_ * denum_;
    denum_ *= rhs.denum_;
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
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs)
{
    num_ *= rhs.num_;
    denum_ *= rhs.denum_;
    return *this;
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