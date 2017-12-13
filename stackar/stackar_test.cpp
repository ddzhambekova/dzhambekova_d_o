#include "stackar.h"

int main()
{
    using namespace std;
    StackAr s;
    s.push(9);
    s.push(7);
    s.push(2);
    s.push(11);
    s.push(1);
    s.push(7);
    cout << "Stack s:" << endl;
    cout << s << endl;
    s.pop();
    cout << "s.pop():" << endl;
    cout << s << endl;
    StackAr s1(s);
    cout << "s1(s): " << endl;
    cout << s1 << endl;
    s1.top() = 16;
    cout << "s1.top() = 16: " << endl;
    cout << s1 << endl;

    StackAr s2;
    StackAr w(s2);
    cout << "Copy from empty: " << endl;
    cout << s2 << endl;

    StackAr s3;
    s3.push(2);
    s3.push(7);
    s3.push(3);
    s3.push(1);
    cout << "Stack s3:" << endl;
    cout << s3 << endl;
    s2 = s3;
    cout << "s2 = s3:" << endl;
    cout << s2 << endl;
    StackAr s4;
    s4.push(3);
    s4.push(7);
    cout << "Stack s4:" << endl << s4 << endl;
    s3 = s4;
    cout << "s3 = s4:" << endl << s3 << endl;

    StackAr s5;
    try
    {
        s5.top();
    }
    catch (int er)
    {
        cout << "Error " << er << ": stack is empty, no top" << endl;
    }
    try
    {
        s5.pop();
    }
    catch (int er)
    {
        cout << "Error " << er << ": stack is empty, popping is impossible" << endl;
    }


    return 0;
}