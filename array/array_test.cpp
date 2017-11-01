#include "array.h"

using namespace std;

int main()
{
    Array a(4);
    cout << a << endl;
    a[0] = 1;
    a[1] = 4;
    a[2] = 3;
    a[3] = 2;
    cout << a << endl;
    int n(a.getsize());
    a.resize(5);
    a[4] = 7;
    cout << a << endl;
    a.insert(2, 10);
    cout << a << endl;
    a.remove(3);
    cout << a << endl;
    Array b(2);
    b[0] = 22;
    b[1] = 33;
    a.insertAr(1, b);
    cout << a << endl;
    a.removeAr(2, 3);
    cout << a << endl;


    return 0;
}