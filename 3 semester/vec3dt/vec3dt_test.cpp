#include "vec3dt.h"

#include <iostream>
#include <sstream>

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Vec3dt<double> v;
    istrm >> v;
    if (istrm.good())
    {
        cout << "Read success: " << str << " -> " << v << endl;
    }
    else
    {
        cout << "Read error: " << str << " -> " << v << endl;
    }
    return istrm.good();
}

int main()
{
    using namespace std;

    testParse("{1.1, 2.2, 3.3}");
    testParse("{1.4,2.0,3.0}");
    testParse("{1.0, 2.0, 3.0");

    Vec3dt<double> a(1.0, 2.0, 3.0);
    cout << "vector a(1.0, 2.0, 3.0)\n" << a << endl;
    Vec3dt<double> b(a);
    cout << "constructor prisvaivaniya b(a)\n" << b << endl;
    bool t(a == b);
    cout << "a==b\n" << t << endl;
    bool t1(a != b);
    cout << "a!=b\n" << t1 << endl;
    a += Vec3dt<double>(2.1, 4.2, 1.3);
    cout << "a+=(2.1, 4.2, 1.3)\n" << a << endl;
    a -= Vec3dt<double>(1.2, 1.0, 2.0);
    cout << "a-=(1.2, 1.0, 2.0)\n" << a << endl;
    a *= 1.5;
    cout << "a*=1.5\n" << a << endl;
    a /= 2.0;
    cout << "a/=2.0\n" << a << endl;
    double q = b.module();
    cout << "module b\n" << q << endl;
    Vec3dt<double> c(2.0, 3.0, 4.0);
    double w = b.skalpr(c);
    cout << "skalyarnoe proizvedenie b*(2.0,3.0,4.0)\n" << w << endl;
    Vec3dt<double> r = b.vectpr(c);
    cout << "vectornoe proizvedenie b*(2.0,3.0,4.0)\n" << r << endl;
    double u = b.angle(c);
    cout << "angle between b and (2.0,3.0,4.0)\n" << u << endl;

    Vec3dt<int> v1(4, 2, 1);
    Vec3dt<int> v2(1, 3, 5);
    int n(2);
    Vec3dt<int> summ(v1 + v2);
    cout << "(4,2,1)+(1,3,5)\n" << summ << endl;
    Vec3dt<int> diff(v1 - v2);
    cout << "(4,2,1)-(1,3,5)\n" << diff << endl;
    Vec3dt<int> mult(v1 * n);
    cout << "(4,2,1)*2\n" << mult << endl;
    Vec3dt<int> div(v2 / n);
    cout << "(1,3,5)/2\n" << div << endl;
    double mod = v1.module();
    cout << "module (4,2,1)\n" << mod << endl;
    double sk = v1.skalpr(v2);
    cout << "skal. pr. (4,2,1)*(1,3,5)\n" << sk << endl;
    Vec3dt<int> vec = v1.vectpr(v2);
    cout << "vect. pr. (4,2,1)*(1,3,5)\n" << vec << endl;
    double ang = v1.angle(v2);
    cout << "angle (4,2,1)^(1,3,5)\n" << ang << endl;

    return 0;
}