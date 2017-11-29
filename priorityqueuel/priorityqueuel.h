#ifndef PRIORITYQUEUEL_H_20171122
#define PRIORITYQUEUEL_H_20171122

#include<iostream>

class PriorityQueueL
{
public:
    PriorityQueueL() = default;
    ~PriorityQueueL()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    PriorityQueueL operator=(const PriorityQueueL& p);
    PriorityQueueL(const PriorityQueueL& p);
    bool isEmpty() const;
    void push(const double& v);
    void pop();
    double& front();
    double& back();

    std::ostream& writeTo(std::ostream& ostrm) const;

private:
    struct Node
    {
        Node(Node* pNext, const double& v)
            : pNext_(pNext)
            , data_(v)
        {
        }
        Node() = default;
        Node* pNext_{ nullptr };
        double data_{ int(0) };
    };
    Node* pHead_{ nullptr };
    Node* pTail_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueL& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif