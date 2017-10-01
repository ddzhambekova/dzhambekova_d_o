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
    cout << "Initialization m = 1/3\n" << m << endl;
    m += Rational(1, 2);
    cout << "Addition m + 1/2\n" << m << endl;
    m -= Rational(1, 6);
    cout << "Subtraction m - 1/6\n" << m << endl;
    m *= Rational(1, 2);
    cout << "Multiplication m * 1/2\n" << m << endl;
    m /= Rational(2, 3);
    cout << "Division m : 2/3\n" << m << endl;
    m += 2;
    cout << "Addition of int m + 2\n" << m << endl;
    m -= 1;
    cout << "Substraction of int m - 1\n" << m << endl;

    Rational k(1, 3);
    Rational* w(&k);
    Rational q(*w);
    cout << "Peredacha po ukazatelyu\n" << q << endl;
    Rational p(4, 9);
    Rational& s(p);
    cout << "Peredacha po ssylke\n" << s << endl;

    bool t = Rational(1, 4) > Rational(1, 2);
    cout << "bool t = 1/4 > 1/2\n" << t << endl;

    bool r = Rational(2, 5) < Rational(3, 5);
    cout << "bool r = 2/5 < 3/5\n" << r << endl;

    bool y = Rational(1, 3) == Rational(2, 6);
    cout << "bool y = 1/3 == 2/6\n"<< y << endl;

    bool x = Rational(1, 3) != Rational(1, 2);
    cout << "bool x = 1/3 != 1/2\n" << x << endl;

    Rational we(Rational(2, 3) ^ 2);
    cout << "Exponentiation we = (2/3)^2\n" << we << endl;

    we *= 2;
    cout << "Multiplication we * 2\n" << we << endl;

    we /= 5;
    cout << "Division we / 5\n" << we << endl;

    we += 1.3;
    cout << "Addition we + 1.3\n" << we << endl;

    we -= 1.2;
    cout << "Substraction we - 1.2\n" << we << endl;

    we *= 2.2;
    cout << "Multiplication we * 2.2\n" << we << endl;

    we /= 2.2;
    cout << "Multiplication we / 2.2\n" << we << endl;

    //Rational er(1, 0);
    
}