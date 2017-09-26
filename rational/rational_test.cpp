#include "rational.h"
#include <iostream>
#include <sstream>

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Rational z;
    istrm >> z;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << z << endl;
    }
    return istrm.good();
}

int main()
{
    using namespace std;

    testParse("{2/5}");
    testParse("{ 2 / 5 }");
    testParse("{2/5");

    Rational m(1, 3);
    cout << "1/3   " << m << endl;
    m += Rational(1, 2);
    cout << "+1/2   " << m << endl;
    m -= Rational(1, 6);
    cout << "-1/6   " << m << endl;
    m *= Rational(1, 2);
    cout << "*1/2   " << m << endl;
    m /= Rational(2, 3);
    cout << ":2/3   " << m << endl;

    Rational d(0, 5);
    d.Normalize(d);
    cout << d << endl;

    Rational k(1, 3);
    Rational* w(&k);
    Rational q(*w);
    cout << q << endl;
    Rational p(4, 9);
    Rational& s(p);
    cout << s << endl;

    bool t = Rational(1, 4) > Rational(1, 2);
    cout << t << endl;

    bool r = Rational(2, 5) < Rational(3, 5);
    cout << r << endl;

    bool y = Rational(1, 3) == Rational(2, 6);
    cout << y << endl;

    bool x = Rational(1, 3) != Rational(1, 2);
    cout << x << endl;


    //Rational er(1, 0);
    
}