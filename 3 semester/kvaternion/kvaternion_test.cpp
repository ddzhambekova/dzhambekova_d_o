#include "kvaternion.h"

#include <iostream>
#include <sstream>

int main()
{
    using namespace std;
    Kvaternion m(1.0, 4.0, 2.0, 1.0);
    Kvaternion n(2.0, 3.0, 5.0, 1.0);
    Kvaternion e(1.0, 1.0, 1.0, 1.0);
    double w = 2.0;
    cout << "matrix m\n" << m << endl;
    cout << "matrix n\n" << n << endl;
    cout << "matrix e\n" << e << endl;
    cout << "double w" << w << endl;
    m += n;
    cout << "m+=n\n" << m << endl;
    m -= e;
    cout << "m-=e\n" << m << endl;
    m *= w;
    cout << "m*=w\n" << m << endl;
    m *= n;
    cout << "m*=n\n" << m << endl;
    double det(m.determ());
    cout << "determinator m\n" << det << endl;
    Kvaternion ntransp(n.transp());
    cout << "transponation n\n" << ntransp << endl;
    Kvaternion x(3.0, 6.0, 5.0, 2.0);
    Kvaternion xinverse(x.inverse());
    cout << "inversion (3,6,5,2)\n" << xinverse << endl;
    Kvaternion g;
    g = m + n;
    cout << "g=m+n\n" << g << endl;
    g = m - n;
    cout << "g=m-n\n" << g << endl;
    g = m * w;
    cout << "g=m*w\n" << g << endl;
    g = w * m;
    cout << "g=w*m\n" << g << endl;
    g = m * n;
    cout << "g=m*n\n" << g << endl;


    return 0;
}