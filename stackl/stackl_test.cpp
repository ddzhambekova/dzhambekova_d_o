#include"stackl.h"

int main()
{
    using namespace std;
    StackL s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    cout << "s: " << s << endl;
    StackL w(s);
    cout << "w(s): " << w << endl;
    w.pop();
    cout << "w.pop(): " << w << endl;
    cout << "w.top(): " << w.top() << endl;
    StackL r = s;
    cout << "r = s: " << r << endl;
    StackL er;
    try
    {
        cout << er.top() << endl;
    }
    catch(int q)
    {
        cout << "Error " << q << ": the stack is empty" << endl;
    }
    try
    {
        er.pop();
    }
    catch (int q)
    {
        cout << "Error " << q << ": the stack is empty" << endl;
    }


    return 0;
}