#include"matrixr.h"

using namespace std;

int main()
{
    MatrixR a(2, 3);
    a.at(0, 0) = 0;
    a.at(0, 1) = 1;
    a.at(0, 2) = 2;
    a.at(1, 0) = 3;
    a.at(1, 1) = 4;
    a.at(1, 2) = 5;
    cout << a << endl;
    try
    {
        a.at(5, 0);
    }
    catch (int er)
    {
        cout << "error " << er << ": index is out of matrix" << endl;
    }
    try
    {
        a.at(-1, 0);
    }
    catch (int er)
    {
        cout << "error " << er << ": index is negative" << endl;
    }
    MatrixR b(2, 3);
    b.at(0, 0) = 5;
    b.at(0, 1) = 7;
    b.at(0, 2) = 1;
    b.at(1, 0) = 4;
    b.at(1, 1) = 4;
    b.at(1, 2) = 2;
    cout << b << endl;
    MatrixR d = a;
    cout << d << endl;
    MatrixR l(a);
    cout << l << endl;
    MatrixR c(3, 1);
    c.at(0, 0) = 2;
    c.at(1, 0) = 3;
    c.at(2, 0) = 4;
    cout << c << endl;
    try
    {
        a += c;
    }
    catch (int er)
    {
        cout << "error " << er << ": different size, addition is impossible" << endl;
    }
    try
    {
        a -= c;
    }
    catch (int er)
    {
        cout << "error " << er << ": different size, subtraction is impossible" << endl;
    }
    try
    {
        a*b;
    }
    catch (int er)
    {
        cout << "error " << er << ": matrix multiplication is impossible" << endl;
    }
    cout << a.isSizeEqual(b) << endl;
    a += b;
    cout << a << endl;
    a -= b;
    cout << a << endl;
    MatrixR r(a * c);
    cout << r << endl;
    

    return 0;
}