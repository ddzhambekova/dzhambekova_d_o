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
    cout << z << endl;
    z += Complex(8.0, 3);
    cout << z << endl;
    z -= Complex(2.0, 1);
    cout << z << endl;
    z *= 2;
    cout << z << endl;
    z *= Complex(2.0, 3);
    cout << z << endl;
    z /= Complex(2.0, 3);
    cout << z << endl;
    z /= 2;
    cout << z << endl;
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9, 9");

    return 0;
}