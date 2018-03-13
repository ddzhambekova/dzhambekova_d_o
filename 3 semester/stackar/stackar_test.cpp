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
    cout << "Stack s: \n" << s << endl;
    s.pop();
    cout << "s.pop(): \n" << s << endl;
    StackAr s1(s);
    cout << "s1(s): \n" << s1 << endl;;
    s1.top() = 16;
    cout << "s1.top() = 16: \n" << s1 << endl;

    StackAr s2;
    StackAr w(s2);
    cout << "Copy from empty: \n" << s2 << endl;

    StackAr s3;
    s3.push(2);
    s3.push(7);
    s3.push(3);
    s3.push(1);
    cout << "Stack s3: \n" << s3 << endl;
    s2 = s3;
    cout << "s2 = s3: \n" << s2 << endl;

    StackAr s4;
    s4.push(3);
    s4.push(7);
    cout << "Stack s4: \n" << s4 << endl;
    s3 = s4;
    cout << "s3 = s4: \n" << s3 << endl;

    StackAr s5;
    s5.push(2);
    s5.push(5);
    s5 = s;
    cout << "s5 = s: \n" << s5 << endl;

    StackAr s6;
    try
    {
        s6.top();
    }
    catch (int er)
    {
        cout << "Error " << er << ": stack is empty, no top" << endl;
    }
    try
    {
        s6.pop();
    }
    catch (int er)
    {
        cout << "Error " << er << ": stack is empty, popping is impossible" << endl;
    }


    return 0;
}