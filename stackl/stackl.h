#ifndef STACKL_H_20171116
#define STACKL_H_20171116

#include<iostream>

class StackL
{
public:
    StackL() = default;
    ~StackL()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
    StackL operator=(const StackL& s);
    StackL(const StackL& s);
    void push(const int& v);
    void pop();
    int& top();
    const int& top() const;
    bool isEmpty() const;

    std::ostream& writeTo(std::ostream& ostrm) const;
    
private:
    struct Node
    {
        Node(Node* pNext, const int& v)
            : pNext_(pNext)
            , data_(v)
        {
        }
        Node* pNext_{ nullptr };
        int data_{ int(0) };
    };
    Node* pHead_{ nullptr };
};


inline std::ostream& operator<<(std::ostream& ostrm, const StackL& rhs)
{
    return rhs.writeTo(ostrm);
}

#endif