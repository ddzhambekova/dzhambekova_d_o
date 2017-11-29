#include "priorityqueuel.h"

int main()
{
    using namespace std;

    PriorityQueueL a;
    a.push(6.2);
    a.push(1.5);
    a.push(3.1);
    a.push(2.2);
    a.push(1.4);
    a.push(7.1);
    a.push(5.3);
    a.push(4.2);
    cout << "Creation: " << a << endl;
    cout << "Print front: " << a.front() << endl;
    cout << "Print back: " << a.back() << endl;
    a.pop();
    cout << "Pop: " << a << endl;
    PriorityQueueL b;
    try
    {
        b.pop();
    }
    catch (int er)
    {
        cout << "Error " << er << ": popping is impossible, queue is empty!" << endl;
    }
    try
    {
        b.front();
    }
    catch (int er)
    {
        cout << "Error " << er << ": front doesn't exist, queue is empty!" << endl;
    }
    try
    {
        b.back();
    }
    catch (int er)
    {
        cout << "Error " << er << ": back doesn't exist, queue is empty!" << endl;
    }


    return 0;
}