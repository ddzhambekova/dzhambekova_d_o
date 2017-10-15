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

    Vec3d v1(4.0, 2.0, 1.0);
    Vec3d v2(1.0, 3.0, 5.0);
    double n(2.0);
    Vec3d summ(v1 + v2);
    cout << "(4,2,1)+(1,3,5)\n" << summ << endl;
    Vec3d diff(v1 - v2);
    cout << "(4,2,1)-(1,3,5)\n" << diff << endl;
    Vec3d mult(v1 * n);
    cout << "(4,2,1)*2\n" << mult << endl;
    Vec3d div(v2 / n);
    cout << "(1,3,5)/2\n" << div << endl;
    double mod = v1.module();
    cout << "module (4,2,1)\n" << mod << endl;
    double sk = v1.skalpr(v2);
    cout << "skal. pr. (4,2,1)*(1,3,5)\n" << sk << endl;
    Vec3d vec = v1.vectpr(v2);
    cout << "vect. pr. (4,2,1)*(1,3,5)\n" << vec << endl;
    double ang = v1.angle(v2);
    cout << "angle (4,2,1)^(1,3,5)\n" << ang << endl;

    return 0;
}