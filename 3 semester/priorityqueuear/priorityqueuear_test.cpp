#include "priorityqueuear.h"

int main()
{
    using namespace std;

    PriorityQueueAr q1;
    q1.push(5);
    q1.push(3);
    q1.push(2);
    q1.push(4);
    q1.push(7);
    q1.push(1);
    q1.push(9);
    q1.push(8);
    cout << "q1: \n" << q1 << endl;
    q1.pop();
    cout << "q1.pop(): \n" << q1 << endl;
    cout << "q1.front(): \n" << q1.front() << endl;
    cout << "q1.back(): \n" << q1.back() << endl;

    PriorityQueueAr q2;
    q2.push(12);
    q2.push(10);
    q2.push(17);
    q2.push(11);
    cout << "q2: \n" << q2 << endl;
    q1 = q2;
    cout << "From small to big q1 = q2: \n" << q1 << endl;

    PriorityQueueAr q3;
    q3.push(7);
    q3.push(1);
    cout << "q3: \n" << q3 << endl;
    q3 = q1;
    cout << "From big to small q3 = q1: \n" << q3 << endl;

    PriorityQueueAr q4(q1);
    cout << "q4(q1): \n" << q4 << endl;

    PriorityQueueAr q5;
    q5 = q3;
    cout << "From filled to empty q5 = q3: \n" << q5 << endl;



    return 0;
}