#include "complex.h"
#include <iostream>
#include <sstream>

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Complex z;
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
    Complex z(0.0, 0);
    cout << "Initialization z = 0 + 0i\n" << z << endl;
    z += Complex(8.0, 3);
    cout << "Addition Complex z + (8 + 3i)\n" << z << endl;
    z -= Complex(2.0, 1);
    cout << "Substraction Complex z - (2 + 1i)\n" << z << endl;
    z *= 2;
    cout << "Multiplication int z * 2\n" << z << endl;
    z *= Complex(2.0, 3);
    cout << "Multiplication Complex z * (2 + 3i)\n" << z << endl;
    z /= Complex(2.0, 3);
    cout << "Division Complex z : (2 + 3i)\n" << z << endl;
    z /= 2;
    cout << "Division int z : 2\n" << z << endl;
    z += 4;
    cout << "Addition int z + 4\n" << z << endl;
    z -= 1;
    cout << "Substraction int z - 1\n" << z << endl;
    Complex w(z ^ 2);
    cout << "Exponentiation z^2\n" << w << endl;
    //Complex wsopr(w.sopr);
    //cout << "Complex sopryazhennoe z" << wsopr << endl;
    

    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9, 9");

    return 0;
}