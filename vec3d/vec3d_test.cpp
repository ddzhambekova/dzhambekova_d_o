#include "vec3d.h"

#include <iostream>
#include <sstream>

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Vec3d v;
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

    Vec3d a(1.5, 2.5, 3.0);
    cout << "vector a(1.5, 2.5, 3.0)\n" << a << endl;
    Vec3d b(a);
    cout << "constructor prisvaivaniya b(a)\n" << b << endl;
    bool t(a == b);
    cout << "a==b\n" << t << endl;
    bool t1(a != b);
    cout << "a!=b\n" << t1 << endl;
    a += Vec3d(2.1, 4.2, 1.3);
    cout << "a+=(2.1, 4.2, 1.3)\n" << a << endl;
    a -= Vec3d(1.2, 1.0, 2.0);
    cout << "a-=(1.2, 1.0, 2.0)\n" << a << endl;
    a *= 1.5;
    cout << "a*=1.5\n" << a << endl;
    a /= 2.0;
    cout << "a/=2.0\n" << a << endl;
    double q = b.module();
    cout << "modul b\n" << q << endl;
    Vec3d c(1.0, 2.0, 3.0);
    double w = b.skalpr(c);
    cout << "skalyarnoe proizvedenie b*(1.0,2.0,3.0)\n" << w << endl;
    Vec3d r = b.vectpr(c);
    cout << "vectornoe proizvedenie b*(1.0,2.0,3.0)\n" << r << endl;
    double u = b.angle(c);
    cout << "angle between b and (1.0,2.0,3.0)\n" << u << endl;

    return 0;
}