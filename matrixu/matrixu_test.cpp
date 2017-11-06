#include "matrixu.h"

using namespace std;

int main()
{
    MatrixU a(2, 3);
    a.at(0, 0) = 0;
    a.at(0, 1) = 1;
    a.at(0, 2) = 2;
    a.at(1, 0) = 3;
    a.at(1, 1) = 4;
    a.at(1, 2) = 5;
    cout << a << endl;
    MatrixU b(2, 3);
    b.at(0, 0) = 5;
    b.at(0, 1) = 7;
    b.at(0, 2) = 1;
    b.at(1, 0) = 4;
    b.at(1, 1) = 4;
    b.at(1, 2) = 2;
    cout << b << endl;
    MatrixU d = a;
    cout << d << endl;
    MatrixU l(a);
    cout << l << endl;
    MatrixU c(3, 1);
    c.at(0, 0) = 2;
    c.at(1, 0) = 3;
    c.at(2, 0) = 4;
    cout << c << endl;
    cout << a.isSizeEqual(b) << endl;
    a += b;
    cout << a << endl;
    a -= b;
    cout << a << endl;
    MatrixU r(a * c);
    cout << r << endl;


    return 0;
}